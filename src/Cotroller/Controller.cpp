#include "Controller.h"


namespace s21 {

    Controller::Controller(Model * model_) : model(model_) {}
    void Controller::set_path_file(const std::string& file_path) {
         model->set_path_file(file_path);
    }
    void Controller::write_to_file_weights_graph() { 
        model->write_to_file_weights();
    }
    void Controller::set_traininh_sample_share(const double& shape) noexcept { 
        model->set_training_sample_share(shape);
    }
    void Controller::train_graph_network() { 
        model->train_graph_network();
    }
    void Controller::test_graph_network() { 
        model->test_graph_network();
    }
    vector_ Controller::predict_graph_network(vector_ data) { 
        return model->predict_graph_network(data);
    }
    double Controller::get_average_accuracy() const noexcept { 
        return model->get_average_accuracy();
    }
    double Controller::get_precision() const noexcept { 
        return model->get_precision();
    }
    double Controller::get_recall() const noexcept { 
        return model->get_recall();
    }
    double Controller::get_f_measure() const noexcept { 
        return model->get_f_measure();
    }
    void Controller::set_epochs(const size_t& val) noexcept { 
        model->set_epochs(val);
    }
}