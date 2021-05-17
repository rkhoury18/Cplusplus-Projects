#include<string>
#include<iostream>
#include <vector>
#include <sstream>



struct BNode{

    std::string val;

    // this will contain

    // "x1", "x2"... "xn" in non-leaf nodes

    // "0" or "1" in leaf nodes
    BNode* left;
    BNode* right;

};

BNode* newNode(std::string x){

   BNode* tmp = new BNode;
     tmp->val = x;
     tmp->left = NULL;
     tmp->right = NULL;

    return tmp;

}



BNode* createTree(BNode* root, int row, int size){
  std::string val;
  std::stringstream ss;
  ss << row;

  if(row < size+1){
   val = "x"+ ss.str();
  }

  else{
   val="0";
  }

  root = newNode(val);

  if(row < size+1){
   root->left = createTree(root->left, row+1, size);
   root->right = createTree(root->right, row+1, size);
  }

 return root;


}

BNode* determinenode(BNode* tree,std::string entry){
  std::string number="";
  BNode* tmp = tree;

  for(int i=0;i<entry.size();i++){
    number=entry[i];

    if(number=="0"){
     tmp = tmp->left;
    }

   else  if(number=="1"){
     tmp=tmp->right;
   }


  }
  return tmp;
}


BNode* addEntry(BNode* root,std::string entry){
 determinenode(root,entry)->val="1";
  return root;

}


BNode* build_bt(const std::vector<std::string>& fvalues){

  BNode* build_bt;
  build_bt = createTree(build_bt, 1, fvalues[0].size());

   for (int i=0;i<fvalues.size();i++){
    addEntry(build_bt,fvalues[i]);

  }

 return build_bt;

}

std::string eval_bt(BNode* root, const std::string input){
  return determinenode(root,input)->val;
}



int main(){

 BNode* tree;

 std::vector<std::string> fvalues;

 fvalues.push_back("101000");
 fvalues.push_back("010001");
 fvalues.push_back("001000");
 fvalues.push_back("010101");

 tree=build_bt(fvalues);

 std::cout<<eval_bt(tree,"100000")<<std::endl;

 std::cout<<eval_bt(tree,"000000")<<std::endl;

 std::cout<<eval_bt(tree,"001000")<<std::endl;

 std::cout<<eval_bt(tree,"010101")<<std::endl;

 std::cout<<eval_bt(tree,"010000")<<std::endl;


}
