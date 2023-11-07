#include "../Model/Model.h"


namespace s21 {
class Controller { 
    Controller() = delete;
    Controller(Model * model_) : model(model_) {}
    
    private:
    Model * model; 
};
}