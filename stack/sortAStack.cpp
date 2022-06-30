void sortInsert(stack<int> &stack, int num)
{
   // base case
   if(stack.empty() || stack.top()<num)
   {
       stack.push(num);
       return;
   }
   int value = stack.top();
   stack.pop();
   // recursive call
   sortInsert(stack,num);
   stack.push(value);
}
void sortStack(stack<int> &stack)

{
    // base case
   if(stack.empty() == true)
      return;
    //Take out all the elements from stack 
    //it it become empty
    //After that start inserting into stack with condition
    //if element is greater than stack ka top then insert 
    //otherwise take out elemnets till it become greater than top then insert 
    //and again start inserting the elements 
   int value = stack.top();
   stack.pop();
   // recursive call
  sortInsert(stack,value);
}