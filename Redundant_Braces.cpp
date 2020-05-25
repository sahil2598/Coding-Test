int Solution::braces(string A) {
    stack <char> s;
    
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==')')
        {
           int flag=0;
           int found=0;
           while(!s.empty())
           {
               char p=s.top();
               s.pop();
               
               if(p=='(')
               {
                   found=1;
                    break;
               }
                
                if(p=='+'||p=='-'||p=='*'||p=='/'||p=='%')
                    flag=1;
           }
           
           if(found==0&&s.empty())
                return 1;
           
           if(flag==0)
                return 1;
                
           // if(!s.empty()&&s.top()=='(')
             //   return 1;
        }
        else
            s.push(A[i]);
    }
    return 0;
}
