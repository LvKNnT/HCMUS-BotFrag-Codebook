#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef pair<int,int> Interval;
const Interval NO_INTERVAL_FOUND = {1,0};
template <class Node_CItr, class Node_Itr, class Cmp_Fn, class _Alloc> //Augmented IT
struct interval_node_update_policy{
    typedef int metadata_type;
    bool doOverlap(Interval i1, Node_CItr i2){
        return (i1.first <= (*i2)->second && (*i2)->first <= i1.second);
    }
    Interval overlapSearch(Interval i){
        for(Node_CItr it = node_begin(); it != node_end();){
            if(doOverlap(i,it)){
                return {(*it)->first, (*it)->second};
            }
            if(it.get_l_child() != node_end() && it.get_l_child().get_metadata() >= i.first){
                it = it.get_l_child();
            }
            else{
                it = it.get_r_child();
            }
        }
        return NO_INTERVAL_FOUND;
    }
    void operator()(Node_Itr it, Node_CItr end_it){
        int max_high = (*it)->second;
        if(it.get_l_child() != end_it){
            max_high = max(max_high,it.get_l_child().get_metadata());
        }
        if(it.get_r_child() != end_it){
            max_high = max(max_high, it.get_r_child().get_metadata());
        }
        const_cast<int&>(it.get_metadata()) = max_high;
    }
    virtual Node_CItr node_begin() const = 0;
    virtual Node_CItr node_end() const = 0;
    virtual ~interval_node_update_policy() {}
};
typedef tree<Interval,null_type,less<Interval>,rb_tree_tag,interval_node_update_policy> IntervalTree;
//All operations include .erase(), .overlapSearch(), .insert()
//Initialize an IT by: "IntervalTree IT;"
int main(){
}
