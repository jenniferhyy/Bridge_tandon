#include <iostream>
#include <vector>
using namespace std;

void main1();
void main2();

int main(){
    main1();
    cout << endl;
    main2();
    return 0;
}

void main1(){
    int input;
    int count1 = 0;
    int count2 = 0;
    int tempArr[100];
    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End your input by typing -1." << endl;
    while (true){
        cin >> input;
        if (input == -1){
            break;
        }
        tempArr[count1] = input;
        count1++;
    }

    int* arr = new int[count1];
    for (int i = 0; i < count1; i++){
        arr[i] = tempArr[i];
    }
    
    int num;
    cout << "Please enter a number you want to search." << endl;
    cin >> num;
    for (int i = 0; i < count1; i++){
        if (arr[i] == num){
            count2++;
        }
    }

    int* arr2 = new int[count2];
    int index = 0;
    for (int i = 0; i < count1; i++){
        if (arr[i] == num){
            arr2[index] = i + 1;
            index++;
        }
    }
    if (count2 > 0){
        cout << num << " shows in lines ";
        for (int i = 0; i < count2; i++){
            if (i != count2 - 1){
                cout << arr2[i] << ", ";
            } else {
                cout << arr2[i] << ".";
            }
        }
    } else {
        cout << num << " does not appear in the input.";
    }

    delete[] arr;
    delete[] arr2;
}

void main2(){
    vector<int> inputvector;
    vector<int> outputvector;
    int input;
    int count = 0;
    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End your input by typing -1." << endl;
    while (true){
        cin >> input;
        if (input == -1){
            break;
        }
        inputvector.push_back(input);
        count++;
    }
    int num;
    cout << "Please enter a number you want to search." << endl;
    cin >> num;
    for (int i = 0; i < count; i++){
        if (inputvector[i] == num){
            outputvector.push_back(i + 1);
        }
    }
    if (outputvector.size() > 0){
        cout << num << " shows in lines ";
        for (int i = 0; i < outputvector.size(); i++){
            if (i != outputvector.size() - 1){
                cout << outputvector[i] << ", ";
            } else {
                cout << outputvector[i] << ".";
            }
        }
    }
}
