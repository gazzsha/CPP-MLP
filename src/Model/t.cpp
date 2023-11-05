#include <iostream> 
#include <vector>
#include <functional>

bool cmp(int x,int y) { 
    return y >= x;
}

std::vector<int>::iterator fun(std::vector<int>& vec,std::function<bool(int,int)> pred,const int& m) {
    for (auto it = vec.begin(); it != vec.end(); it++) { 
        if (pred(m,*it)) { 
            for (auto it_ = it; it_ != vec.end(); it_++) { 
                if (*it_ < m){
                    std::iter_swap(it,it_);
                    break;
                } 
            }
        }
    }
    auto it = vec.begin();
    for (;it != vec.end();) { 
        if (*it < m) it++;
        else return it;
    }
    return it;
}

int main() { 
int n;
std::vector<int> vec;
std::cin>>n;
for (int i = 0; i < n; i++) { 
int num;
std::cin>>num;
vec.push_back(num);}
int m;
std::cin>>m;
auto it = fun(vec,&cmp,m);
std::cout <<  it - vec.begin() << "\n" << vec.end() - it;
}
