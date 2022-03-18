class Solution {
  public:
    
    Node* parentMappingGetTarget(Node* root, int target, map< Node*,Node* > &findParent)
    {
        //ek temp node banna lo jo target node store karega aur last me return maar dena
        Node* temp=NULL;
        
        //level ordr traversal se chalenge hum log
        queue<Node*>q;
        //root ka parent kuch nai hga toh NULL daal do
        findParent[root]=NULL;
        q.push(root);
        
        while(!q.empty())
        {
            Node* curr=q.front();
            q.pop();
            //check kar lo ye node ka data target ke equal toh nai hai
            if(curr->data==target)
                temp=curr;
            
            if(curr->left!=NULL)
            {
                //matlb ish left child ka parent curr node hga and q me push hga
                findParent[curr->left]=curr;
                q.push(curr->left);
                
            }
            if(curr->right!=NULL)
            {
                //matlb ish left child ka parent curr node hga
                findParent[curr->right]=curr;
                q.push(curr->right);
                
            }
            
        }
        return temp;
    }
    
    int burnTree(Node* targetNode,map<Node*,Node*> &findParent )
    {
        //yaha pe humme ek map bana hai aur ek queue banna lena hai
        //queue me element ko push karenge aur map me ush element ke node ke value
        //ko true mark dnge matlb wo visit ho chuka yaani burn ho gya hai phle
        //check karenge left, right aur parent jo burn nai hga ushe queue me daal lo
        //aur sabko burn kar do
        //agr queue me kuch operation hga matlb new nodes aayenge tbhi burning hua hai nodes ka
        //so agr kuch bhi hua hga tb he time ko increment karna warna nai
        
        //visted wala map banna lo jisse pata chalega phle burn toh nai ho gya
        map<Node*,bool> visited;
        //queue banna lo new elements left ,parent aur right ko push karenge
        queue<Node*> q;
        
        //queue me sabse phle target node ko daal do 
        q.push(targetNode);
        //iska mtlb wo burn ho gya ya visited hai toh map me true kar do
        visited[targetNode]=true;
        //time ko track krne ke lie
        int burntime=0;
        
        while(!q.empty())
        {
            
            bool anychange=false;
            int size=q.size();
            //jitna element rahega like uske parent, left ,right so max size 3 hga sabko processs karna hga
            for(int i=0; i<size ; i++)
            {
                Node* curr=q.front();
                q.pop();
                
                //check akr lo left child hai toh queue me daal do aur visited mar do 
                if(curr->left!=NULL && !visited[curr->left])//matlb left child hai aur vsited bhi nai hai
                {
                    q.push(curr->left);//q me daal dia
                    anychange=true;//kuch operation hua hai koi burn hga a(visited matlb burn)
                    visited[curr->left]=true;//ye wala ab visted ho gya (burn ho gya)
                }
                //check akr lo right child hai toh queue me daal do aur visited mar do 
                if(curr->right!=NULL && !visited[curr->right])//matlb right child hai aur vsited bhi nai hai
                {
                    q.push(curr->right);//q me daal dia
                    anychange=true;//kuch operation hua hai koi burn hga a(visited matlb burn)
                    visited[curr->right]=true;//ye wala ab visted ho gya (burn ho gya)
                }
                //check akr lo parent hai toh queue me daal do aur visited mar do 
                if(findParent[curr]!=NULL && !visited[findParent[curr]])//matlb parent hai aur vsited bhi nai hai
                {
                    q.push(findParent[curr]);//q me daal dia
                    anychange=true;//kuch operation hua hai matlb koi burn hga a(visited matlb burn)
                    visited[findParent[curr]]=true;//ye wala ab visted ho gya (burn ho gya)
                }
            }
            //check kar lo agr kuch operation hua hai kya 
            //new nodes burn hnge tbhi ye true hga
            if(anychange==true)
                burntime++;
        }
        return burntime;
    }
    
    int minTime(Node* root, int target) 
    {
        // humme node ke left aur right ko access  kar skate but we can't track parent
        //parent ko track karne ke liye humlog ek banna lnge jo har element ka parent rakhega as value
        //sabse phle map me parent store kara lo aur target ko khoj ke le aao
        map<Node*,Node*> findParent;
        //Target node khoj ke le aao aur map pe parent bhi daal dena 
        Node* targetNode=parentMappingGetTarget(root,target,findParent);
        
        //ab humare pass node aa gya hai kaha se burn karna hai
        int ans=burnTree(targetNode,findParent);
        return ans;
    }
};