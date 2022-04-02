int longestSubstrDistinctChars (string S)
{
    //Thus problem is similar to k Unique characters 
    //Yaha pe humme bs ditinct characters nekalna hai 
    //iska matlb all unique characters inside a window
    //ek map use karenge jo store karega saare elemets ka value as thier count of ocuurenec
    //jaise he map ka size aur window ka size eqaul ho jaaye matlb all distinct hai
    //Map me duplication nai hota hai
    //agr window ka size baada hai map se malb koi toh repeat hua hai
    //so map se delete karna hai aage wale elements string ke 
    //jab tk wo size equal ya less na ho jaaye
    
    int i=0;//start pointer
    int j=0;//end pointer
    int maxLen=0;
    unordered_map<char,int> m;
    
    while(j<S.length())
    {
        //step 1: map me daal do nai toh warna uska count increase kara do
        m[S[j]]++;
        //Step2: if map size and window size same matlb sab unique he hai waha
        if(m.size() == (j-i+1))
        {
            maxLen=max(maxLen, j-i+1);
            j++;
            
        }
        else if(m.size() < (j-i+1))//iska matlb me repaeted wale hai isliye window se chota hai
        {
           //jitne duplicate wale hai sabko hata de 
           while(m.size() < (j-i+1))
           {
               m[S[i]]--;//count kam kara de
               if(m[S[i]]==0)
                    m.erase(S[i]);
                i++;
           }
           j++;
        }
        
    }
    return maxLen;
}