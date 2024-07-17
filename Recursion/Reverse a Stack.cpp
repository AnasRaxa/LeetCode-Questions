class Solution{
public:

    void insertAtBottom(stack<int> &st,int n){
        
        if(st.empty()){
            st.push(n);
            return;
        }
        
        int num = st.top();
        st.pop();
        
        insertAtBottom(st,n);
        
        st.push(num);
        
        
        
        
        
    }

    void rev(stack<int> &st){
        
        if(st.empty()) return;
        
        int num = st.top();
        st.pop();
        
        rev(st);
        
        
        insertAtBottom(st,num);
        
        
    }

    void Reverse(stack<int> &St){
        
         rev(St);
        
        
    }
};