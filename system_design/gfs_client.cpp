Description
Implement a simple client for GFS (Google File System, a distributed file system), it provides the following methods:

read(filename). Read the file with given filename from GFS.
write(filename, content). Write a file with given filename & content to GFS.
There are two private methods that already implemented in the base class:

readChunk(filename, chunkIndex). Read a chunk from GFS.
writeChunk(filename, chunkIndex, chunkData). Write a chunk to GFS.
To simplify this question, we can assume that the chunk size is chunkSize bytes. (In a real world system, it is 64M). The GFS Client's job is splitting a file into multiple chunks (if need) and save to the remote GFS server. chunkSize will be given in the constructor. You need to call these two private methods to implement read & write methods.

Have you met this question in a real interview?  
Example
GFSClient(5)
read("a.txt")
>> null
write("a.txt", "World")
>> You don't need to return anything, but you need to call writeChunk("a.txt", 0, "World") to write a 5 bytes chunk to GFS.
read("a.txt")
>> "World"
write("b.txt", "111112222233")
>> You need to save "11111" at chink 0, "22222" at chunk 1, "33" at chunk 2.
write("b.txt", "aaaaabbbbb")
read("b.txt")
>> "aaaaabbbbb"

/* Definition of BaseGFSClient
 * class BaseGFSClient {
 * private: map<string, string> chunk_list;
 * public:
 *     string readChunk(string& filename, int chunkIndex) {
 *         // Read a chunk from GFS
 *     }
 *     void writeChunk(string& filename, int chunkIndex,
 *                     string& content) {
 *         // Write a chunk to GFS     
 *     }
 *  };
 */


class GFSClient : public BaseGFSClient {
public:
    int chunkSize;
    map<string, int> chunkNum;

    GFSClient(int chunkSize) {
        // initialize your data structure here
        this->chunkSize = chunkSize;
    }

    // @param filename a file name
    // @return conetent of the file given from GFS
    string read(string& filename) {
        // Write your code here
        // return "" instead of NULL if file do not exist
        if (chunkNum.find(filename) == chunkNum.end()) {
            return "";
        }
        string content = "";
        int size = chunkNum[filename];
        for (int i = 0; i < size; ++i) {
            content += readChunk(filename, i);
        }

        return content;
    }

    // @param filename a file name
    // @param content a string
    // @return void
    void write(string& filename, string& content) {
        // Write your code here
        int length = content.size();
        int num = (length - 1) / chunkSize + 1;
        chunkNum[filename] = num;
        for (int i = 0; i < num; ++i) {
            string sub_content = content.substr(i * chunkSize, chunkSize);
            writeChunk(filename, i, sub_content);
        }
    }
};
