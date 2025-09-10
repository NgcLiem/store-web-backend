#include <iostream>

struct node
{
   int data;//Noi dung cua nut
   node *letf , *right;//Dia chi nut trai , nut phai
};
typedef node *nodeptr;

// ham khoi tao cay
void init_tree(nodeptr &root)
{
   root = NUll;
}

// tao mot nut
nodeptr make_node(int x)
{
   noteptr p = new node; 
   p->data = x;
   p->left = p->right = NULL;
   return p;
}

void input_tree(nodeptr &root)
{
   int n,x;
   root = NULL;
   printf("\nSo phan tu : ");
   scanf("%d" , &n);
   for(int i=1; i<=n; i++)
   {
      printf("Phan tu thu %d : ",i);
      scanf("%d" , &x);
      insert_node(root , x);
   }
}

void NLR(nodeptr root)
{
   if(root!=NULL)
   {
      printf("%d" , root->data);
      NLR(root->left);
      NLR(root->right);
   }
}

void LRN(nodeptr root)
{
   if(root!=NULL)
   {
      LNR(root->left);
      printf("%d" , root->data);
      LNR(root->right);
   }
}

int main(){
    root = make_node(1);
        
    return 0;
}