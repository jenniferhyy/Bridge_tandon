#include <iostream>
#include <fstream> 
#include <string>
#include <list>
#include <vector>
using namespace std;

// Part 1 implementation: 
void openInputFile(ifstream& inFile) {
    string filename;
    cout << "What filename: ";
    cin >> filename;
    inFile.open(filename);
    while (!inFile){
        cout << "No file";
        cout << "What filename: ";
        cin >> filename;
        inFile.clear();
        inFile.open(filename);
    }
}

bool isStart(const string& symbol){
    return symbol == "begin" || symbol == "(" || symbol == "{" || symbol == "[";
}

bool isEnd(const string& symbol){
    return symbol == "end" || symbol == ")" || symbol == "}" || symbol == "]";
}

bool isMatch(const string& start, const string& end) {
    return (start == "begin" && end == "end");
    return (start == "(" && end == ")");
    return (start == "{" && end == "}");
    return (start == "[" && end == "]");
}

bool check(ifstream& file){
    list<string> checker;
    string symbol;
    while (file >> symbol){
        if (isStart(symbol)){
            checker.push_back(symbol);
        }
        else if (isEnd(symbol)){
            if (checker.empty() || !isMatch(checker.back(), symbol)){
                return false;
            }
        }
        checker.pop_back();
    }
    return checker.empty();
}

// Part 2 implementation
template <typename T>
class Queue {
    private:
        vector<T> data;
        size_t startIndex = 0; 
        void reset() {
            if (startIndex > data.size()/2){
                vector<T> newData(data.begin()+startIndex, data.end());
                data.swap(newData);
                startIndex = 0;
            }
        }
    public: 
        void enqueue(const T& value){
            data.push_back(value);
        }
        void dequeue {
            if (!empty){
                ++startIndex;
                reset();
            } else {
                cout << "Queue is empty.";
            }
        }
        T front() const{
            if (!empty){
                return data[startIndex];
            } else {
                cout << "Queue is empty.";
                return T();
            }
        }
        bool empty() const{
            return startIndex >= data.size();
        }
        size_t size() const{
            return data.size() - startIndex;
        }
        void clear(){
            data.clear();
            startIndex = 0;
        }
};

int main(){
    ifstream inFile;
    openInputFile(inFile);
    if (check(inFile)){
        cout << "True";
    } else {
        cout << "False";
    }
    return 0;
}
