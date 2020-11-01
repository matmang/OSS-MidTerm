#include <iostream>
#include <stack> //include stack library

using namespace std;

int main(int argc, const char * argv[]) {
    
    int sum = 0;
    int number = 0;
    int k = 0;
    stack<int> stack; //int type stack create
    
    cin>>number;
    
    for(int i=0; i<number; i++){
        cin>>k;
        if(k == 0){
            sum = sum - stack.top();
            stack.pop();
        }
        else{
            stack.push(k);
            sum = sum + stack.top();
        }
    }
    cout << sum << endl;
    
    return 0;
}