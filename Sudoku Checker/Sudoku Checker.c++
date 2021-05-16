#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <vector>

int twod_to_oned(int row, int col, int rowlen){
    return row*rowlen+col;
}

int mfind(int n, const std::vector<int>& v){
    int m=-1;                                   
    for(int i=0;i<v.size();i++){
        if (v[i]==n){
            m=i;                                
          return m;
        }
    }
    return m;                                   
}

bool check_sequence(const std::vector<int>& v){
    bool verify;                                                          
    for (int i=1;i<=v.size();i++){              
        verify=true;						   
        if(mfind(i,v)==-1){
            return false;
        }   
    }
    return true;                             
}


void get_row(int r, const std::vector<int>& in, std::vector<int>& out){
    int side=std::sqrt(in.size());
    for(int c=0;c<side;c++){
        out.push_back(in[twod_to_oned(r,c,side)]);
    }
}


void get_col(int c, const std::vector<int>& in, std::vector<int>& out){
   int side=std::sqrt(in.size());
   for (int r=0;r<side;r++){
    out.push_back(in[twod_to_oned(r,c,side)]);
   }
}


void get_subsq(int subs, const std::vector<int>& in, std::vector<int>& out){
    int side=std::sqrt(in.size());
    int sidesub=std::sqrt(side);
    int n;                            
    n=subs-((subs/sidesub)*sidesub);  
                                      
    for (int i=0;i<sidesub;i++){
      int r=i+(sidesub*(subs/sidesub));   
        for(int c=n*sidesub;c<sidesub+(n*sidesub);c++){     
            out.push_back(in[twod_to_oned(r,c,side)]);      
        }
    }

}


bool valid_sudoku(const std::vector<int>& g){
    int side = std::sqrt(g.size());
    std::vector<int> seq;

    for(int i = 0; i < side; i++){
        seq.clear();
        get_row(i, g, seq);

        if(!check_sequence(seq)){
            return false;
        }
    }

  
    for(int i = 0; i < side; i++){
        seq.clear();
        get_col(i,g,seq);

        if(!check_sequence (seq)){
            return false;
        }
    }
    
   for(int i = 0; i < side; i++){
        seq.clear();
        get_subsq(i,g,seq);

        if(!check_sequence (seq)){
            return false;
        }
    }
    return true;
}



int main(){

    std::vector<int> s;
    std::string filename;

    std::cout << "please enter name of file containing the sudoku" << std::endl;
    std::cin >> filename;

    std::ifstream infile;
    infile.open(filename);

    if(!infile.is_open()){
        std::cout << "error, can't open input file" << std::endl;
        return EXIT_FAILURE;
    }

    int tmp;

    while(infile >> tmp){
        s.push_back(tmp);
    }

    int side = std::sqrt(s.size());
    
    for(int i = 0; i < side; i++){
        for(int j = 0; j < side; j++){
            std::cout << s[twod_to_oned(i,j,side)] << " ";
        }
        std::cout << std::endl;
    }

    bool valid = valid_sudoku(s);

    if(valid){
        std::cout << "valid" << std::endl;
    }
    else{
        std::cout << "not valid" << std::endl;
    }

}
