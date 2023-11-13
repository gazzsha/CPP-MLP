#include "Graph.h"

namespace s21 {
Graph::Graph(const size_t& count_hidden_layers_)
    : graph_network(std::make_unique<GraphPreceptron>(count_hidden_layers_)) {}

void Graph::TrainNetwork(Input& input_train, const size_t& epochs) {
  input_train.GetData();
  for (size_t i = 0; i < epochs; ++i) {
    for (size_t j = 0; j < input_train.all_neurons_tests_.size(); ++j) {
      graph_network->train(input_train.all_neurons_tests_[j],
                           input_train.answer[j]);
    }
  }
}

void Graph::TrainWithoutEpochs(Input& input_train) {
  input_train.GetData();
  for (size_t j = 0; j < input_train.all_neurons_tests_.size(); ++j) {
    graph_network->train(input_train.all_neurons_tests_[j],
                         input_train.answer[j]);
  }
}

// size_t Graph::get_epochs() const noexcept { return epochs; }
//  void Graph::set_training_sample_share(const double& val) noexcept {
//    training_sample_share = val;
//  }
vector_ Graph::PredictVector(vector_ input_stat) {
  graph_network->Predict(input_stat);
  return graph_network->get_output_vector();
}

void Graph::set_count_hidden_layer(const size_t& count_) {
  // GraphPreceptron* cur = graph_network;
  // GraphPreceptron* new_network = new GraphPreceptron(count_);
  // graph_network = new_network;
  // delete cur;
  graph_network.reset(std::make_unique<GraphPreceptron>(count_).release());
}
// void Graph::set_path_file_test(const std::string& path_file) {
//   input_test.file_path = path_file;
//   average_accuracy_vec.clear();
//   precision_vec.clear();
//   recall_vec.clear();
//   f_measure_vec.clear();
//   time_vec.clear();
// }
// void Graph::set_path_file_train(const std::string& path_file) {
//   input_train.file_path = path_file;
// }
// double Graph::get_time() const noexcept { return time.count(); }

// void Graph::collection_data_of_metrics(const vector_& result,
//                                        const vector_& expect, size_t& tp,
//                                        size_t& tn, size_t& fp,
//                                        size_t& fn) const noexcept {
//   for (const auto& elem : result) {
//     if (elem > 0.5) {
//       if (is_right_letter(result, expect, elem))
//         ++tp;
//       else
//         ++fp;
//     } else {
//       if (is_right_letter(result, expect, elem))
//         ++fn;
//       else
//         ++tn;
//     }
//   }
// }
void Graph::WriteToFileWeights(const std::string& path) {
  graph_network->write_to_file_weights(path);
}
void Graph::ReadFromFileWeights(const std::string& path) {
  graph_network->read_from_file_weights(path);
}

// size_t Graph::count_of_true_result(const vector_& vec) const noexcept {
//   size_t temp_count = 0;
//   for (const auto& v : vec)
//     if (v > 0.5) temp_count++;
//   return temp_count;
// }
// double Graph::get_average_accuracy() const noexcept { return
// average_accuracy; }
// double Graph::get_precision() const noexcept { return precision; }
// double Graph::get_recall() const noexcept { return recall; }
// double Graph::get_f_measure() const noexcept { return f_measure; }
// void Graph::set_epochs(const size_t& val) noexcept { epochs = val; }
char Graph::PredictLetter(const vector_& input) const noexcept {
  graph_network->Predict(input);
  auto res = graph_network->get_output_vector();
  auto it = std::max_element(res.begin(), res.end());
  auto index = it - res.begin();
  return index + 65;
}

// vector_ Graph::get_average_accuracy_vec() const noexcept {
//   return average_accuracy_vec;
// }
// vector_ Graph::get_precision_vec() const noexcept { return precision_vec; }
// vector_ Graph::get_recall_vec() const noexcept { return recall_vec; }
// vector_ Graph::get_f_measure_vec() const noexcept { return f_measure_vec; }
// vector_ Graph::get_time_vec() const noexcept { return time_vec; }
// double Graph::get_average_accuracy_of_full_train() const noexcept {
//   double sum = 0;
//   for (const auto& v : average_accuracy_vec) sum += v;
//   return sum / static_cast<double>(get_epochs());
// }
// double Graph::get_average_precision_of_full_train() const noexcept {
//   double sum = 0;
//   for (const auto& v : precision_vec) sum += v;
//   return sum / static_cast<double>(get_epochs());
// }
// double Graph::get_average_recall_of_full_train() const noexcept {
//   double sum = 0;
//   for (const auto& v : recall_vec) sum += v;
//   return sum / static_cast<double>(get_epochs());
// }
// double Graph::get_average_f_measure_of_full_train() const noexcept {
//   double sum = 0;
//   for (const auto& v : f_measure_vec) sum += v;
//   return sum / static_cast<double>(get_epochs());
// }
// double Graph::get_full_time_of_full_train() const noexcept {
//   double sum = 0;
//   for (const auto& v : time_vec) sum += v;
//   return sum;
// }
// vector_ Graph::get_vector_epochs() const noexcept {
//   vector_ temp;
//   for (size_t i = 0; i < epochs; ++i) {
//     temp.push_back(i + 1);
//   }
//   return temp;
// }

void Graph::CrossValidation(Input& input_train, const size_t& k) {
  input_train.GetData();
  std::vector<std::pair<size_t, size_t>> part;
  size_t part_of_k = input_train.all_neurons_tests_.size() / k;
  for (size_t i = 0; i < k; ++i) {
    part.push_back(
        std::make_pair<size_t, size_t>(i * part_of_k, part_of_k * (i + 1) - 1));
  }
  auto index_predict = k - 1;
  for (size_t l = 0; l < k; ++l) {
    for (size_t j = 0; j < k; ++j) {
      if (j != index_predict) {
        for (auto i = part[j].first; i <= part[j].second; ++i) {
          graph_network->train(input_train.all_neurons_tests_[i],
                               input_train.answer[i]);
        }
      } else {
        for (auto i = part[j].first; i <= part[j].second; ++i) {
          graph_network->Predict(input_train.all_neurons_tests_[i]);
        }
      }
    }
    --index_predict;
  }
}
}  // namespace s21