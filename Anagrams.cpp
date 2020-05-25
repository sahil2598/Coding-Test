vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    vector <vector<int>> answer;
    
    int hash[A.size()][26]={0};
    int k=0;
    for(int i=0;i<A.size();i++)
    {
        int h[26]={0};
        int len=A[i].length();
        for(int j=0;j<len;j++)
        {
            h[A[i][j]-'a']++;
        }
        int idx=-1;
        for(int j=0;j<k;j++)
        {
            int flag=0;
            for(int l=0;l<26;l++)
            {
                if(h[l]!=hash[j][l])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
               idx=j;
               break;
            }
        }
        if(idx!=-1)
        {
            answer[idx].push_back(i+1);
        }
        else
        {
            for(int j=0;j<26;j++)
                hash[k][j]=h[j];
            vector<int> a(1,i+1);
            answer.push_back(a);
            k++;
        }
    }
    
    return answer;
}
