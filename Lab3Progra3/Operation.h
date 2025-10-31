#ifndef OPERATION_H
#define OPERATION_H
#include <string>
using std::string;

enum class OpType{INSERT,DELETE,REPLACE};
struct Operation{
    OpType type;
    std::size_t pos;
    string oldValue;
    string newValue;
    //Construct
    Operation(){
        this->newValue = "a";
        this->oldValue = "b";
        this->type = OpType::INSERT;
        this->pos = -1;
    };
    Operation(string oldValue,string newValue,OpType typeOp,int pos){
        this->oldValue=oldValue;
        this->newValue = newValue;
        this->type = typeOp;
        this->pos = pos;
    }
};
#endif // OPERATION_H
