#include <iostream>
#include <vector>

using namespace std;


// implementing stack 

struct Stack{
    vector<int> nums;
    int top;


    void init(){
        top = -1;
        nums.clear();
    }

    bool isfull(){
        return false;
    }

    bool isempty(){
        return top == -1;
    }

    void push(int val){
        nums.push_back(val);
        top+=1;

    }

    int pop(){
        if(isempty()) {
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        int val = nums[top];
        nums.pop_back();
        top -= 1;
        return val;
    }

    int peek(){
        if(isempty()) {
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        return nums[top];


    }

    bool isvalid(string s, Stack st){
        st.init();
        for(char c : s){
            if(c == '(' || c == '{' || c == '[') st.push(c);
            
            else{
                if(st.isempty()) return false;
                char to = top;
                st.pop();

                if ((c == ')' && top != '(') ||
                        (c == '}' && top != '{') ||
                        (c == ']' && top != '['))
                        return false;
            }
        }
        return st.isempty();


    }
    

};





int main(){
    Stack s;
    s.init();
    string sr = "Data Structure";
    for(char c : sr) s.push(c);

    string rev = "";
    while(!s.isempty()){
        rev += s.peek();
        s.pop();
    }

    cout << "Reversed" << rev << endl;
}