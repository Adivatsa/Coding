class Solution{
public:
    int vaccine=0;
    int supplyVaccine(Node* root){
       
       //If anyone of the child wants vaccine then parent has to give vaccine
       //if parent has been covered by child then it can return that i have got 
       //if both the children has been covered then parent only need 
       
       //it is the case of single child
       if(vaccount(root)=="not vaccinated")
            vaccine++;
            
        return vaccine;
    }
    
    string vaccount(Node* root)
    {
        //vaccinated means no need of vaccine
        //not vaccinated means he wants parent vaccine karid ke le kar aaye
        //need vaccine means I will go and puchase vaccine 
        //Base case 
        //if null means he does not want and also got 
        if(root==NULL)
            return "vaccinated";
            
        //for left and right child
        string lchild=vaccount(root->left);
        string rchild=vaccount(root->right);
        
        //if anyone of child not vaccine then we need one vaccine by parent
        if(lchild=="not vaccinated" || rchild=="not vaccinated")
        {
            vaccine++;
            return "need vaccine";
        }//if anyone of the child has got to buy vaccine then it parent will be vaccinated 
        else if(lchild=="need vaccine" || rchild=="need vaccine")
            return "vaccinated";
        else//both child are vaccinated so parent will not vaccinated
            return "not vaccinated";
    }
};