//
//  house_selection_with_full_services.h
//  AirbnbCodingChallenge
//
//  Created by Xiaochong Zhang on 7/29/25.
//
// https://www.1point3acres.com/bbs/thread-1138602-1-1.html
/**
 Input: a list of available rent house service and price like (wifi,50), (parking, 30), (parking,TV,70). Also provide a list of wanted services like (WiFi, parking)

 Output: find the minimum cost to get all wanted services and return the combinations of items to choose
 */

#ifndef house_selection_with_full_services_h
#define house_selection_with_full_services_h
#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<unordered_map>
#include<unordered_set>

using namespace std;

struct House {
    House(vector<string> s, int p) {
        services = s;
        price = p;
    }
    vector<string> services;
    int price;
};

struct ProcessedHouse {
    int service_mask;
    int idx;
    int price;
};

pair<int, vector<int>> getMinPriceToCoverAllServices(vector<House>& houses, vector<string>& required_service) {
    // step 1: service id mapping
    unordered_map<string, int> service_to_id;
    int next_id = 0;
    unordered_set<string> service_set;
    // we assume all the services in the houses will cover the required service; therefore
    // we don't iterate the required service at here
    for(House h : houses) {
        for(string service: h.services) {
            service_set.insert(service);
        }
    }
    for(string service: service_set) {
        service_to_id[service] = next_id;
        next_id += 1;
    }
    int total_service_num = next_id;
    
    // step 2: generate the target mask based on the service to id map and required_service input
    int target_mask = 0;
    for(string& service: required_service) {
        target_mask |= (1<<service_to_id[service]);
    }
    
    // step 3: generate each house mask
    vector<ProcessedHouse> proc_houses;
    for(int i = 0; i < houses.size(); ++i) {
        int service_mask = 0;
        for(string service: houses[i].services) {
            service_mask |= (1<<service_to_id[service]);
        }
        proc_houses.push_back({service_mask, i, houses[i].price});
    }
    
    // step 4: dp logic
    int max_mask_val = 1 << total_service_num;
    vector<int> dp(max_mask_val, INT_MAX);
    dp[0] = 0; // initialization of the no service combination case
    vector<pair<int, int>> parentService(max_mask_val, {-1,-1});
    
    for(ProcessedHouse& house: proc_houses) {
        for(int covered_mask = 0; covered_mask < max_mask_val; ++covered_mask) {
            if(dp[covered_mask] == INT_MAX) {
                continue;
            }
            int new_mask = covered_mask | house.service_mask;
            long long new_price = (long long)dp[covered_mask] + house.price;
            if(dp[new_mask] > new_price) {
                dp[new_mask] = (int)new_price;
                parentService[new_mask] = {covered_mask, house.idx};
            }
        }
    }
    
    // --- Step 5: Get the Minimum Price and Reconstruct Combination ---
    // The key fix: Find the minimum price among all masks that *cover* the target_mask.
    int min_total_price = INT_MAX;
    int optimal_final_mask = -1; // Stores the actual mask that yielded the min_total_price

    for (int i = 0; i < max_mask_val; ++i) {
        // Check if mask 'i' is a superset of target_mask (i.e., covers all required services)
        if ((i & target_mask) == target_mask) {
            if (dp[i] < min_total_price) {
                min_total_price = dp[i];
                optimal_final_mask = i; // Store this specific mask for reconstruction
            }
        }
    }

    std::vector<int> selected_house_ids;
    // If no mask covering the target was reachable, no solution exists.
    if (min_total_price == INT_MAX) {
        return {INT_MAX, {}}; // Return max price and empty list
    }

    // Reconstruct the path from the optimal_final_mask
    int current_mask_for_reconstruction = optimal_final_mask;
    while (current_mask_for_reconstruction > 0) {
        // Retrieve the parent information
        auto p_info = parentService[current_mask_for_reconstruction];
        // Add the house index that led to this state
        selected_house_ids.push_back(p_info.second);
            
        // Move to the previous mask state in the optimal path
        current_mask_for_reconstruction = p_info.first;
    }
        
    // The indices are collected in reverse order during backtracking, so reverse them for correct order.
    std::reverse(selected_house_ids.begin(), selected_house_ids.end());
    
    return {min_total_price, selected_house_ids};
}


#endif /* house_selection_with_full_services_h */


// Objective C test case
//
//  HouseSelectionWithFullServicesTest.m
//  AirbnbCodingChallengeUnitTests
//
//  Created by Xiaochong Zhang on 7/30/25.
//

#import <XCTest/XCTest.h>
#include "../AirbnbCodingChallenge/house_selection_with_full_services.h"

@interface HouseSelectionWithFullServicesTest : XCTestCase

@end

@implementation HouseSelectionWithFullServicesTest

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testExampleIsCoveredOverlapHouse {
    // This is an example of a functional test case.
    // Use XCTAssert and related functions to verify your tests produce the correct results.
    vector<House> house_list = {
        {{"wifi", "parking"}, 70},
        {{"shower", "bbq"}, 50},
        {{"seaview", "parking", "wifi"}, 150},
        {{"TV", "shower"}, 40}
    };
    
    vector<string> required_services = {"wifi", "parking", "shower"};
    pair<int, vector<int>> result = getMinPriceToCoverAllServices(house_list, required_services);
    
    // 3. Define Expected Output
    int expectedMinPrice = 110;
    vector<int> expectedIndices = {0, 3}; // House 0 (70) and House 3 (40)

    // 4. Assertions (using XCTest macros)
    // Assert Price
    XCTAssertEqual(result.first, expectedMinPrice, @"Min price assertion failed.");

    // Assert Selected Indices (Vector Comparison - Method 1 from earlier discussion)
    // Check sizes first
    XCTAssertEqual(result.second.size(), expectedIndices.size(),@"Selected indices vector size mismatch.");

    // Then check each element if sizes match
    if (result.second.size() == expectedIndices.size()) {
        for (size_t i = 0; i < result.second.size(); ++i) {
            XCTAssertEqual(result.second[i], expectedIndices[i],@"Selected index at position %zu mismatch.", i);
            }
    }
}

- (void)testExampleIsSame {
    // This is an example of a functional test case.
    // Use XCTAssert and related functions to verify your tests produce the correct results.
    vector<House> house_list = {
        {{"shower", "parking"}, 50},
        {{"shower", "parking"}, 40},
        {{"shower", "parking"}, 35},
        {{"shower", "parking"}, 75}
    };
    
    vector<string> required_services = {"parking", "shower"};
    pair<int, vector<int>> result = getMinPriceToCoverAllServices(house_list, required_services);
    
    // 3. Define Expected Output
    int expectedMinPrice = 35;
    vector<int> expectedIndices = {2};
    // 4. Assertions (using XCTest macros)
    // Assert Price
    XCTAssertEqual(result.first, expectedMinPrice, @"Min price assertion failed.");

    // Assert Selected Indices (Vector Comparison - Method 1 from earlier discussion)
    // Check sizes first
    XCTAssertEqual(result.second.size(), expectedIndices.size(),@"Selected indices vector size mismatch.");

    // Then check each element if sizes match
    if (result.second.size() == expectedIndices.size()) {
        for (size_t i = 0; i < result.second.size(); ++i) {
            XCTAssertEqual(result.second[i], expectedIndices[i],@"Selected index at position %zu mismatch.", i);
            }
    }
}

@end
