#ifndef DNN_H
#define DNN_H

#include "spdlog/spdlog.h"
namespace tensorflow { // forward declarations...
class Session;
class Tensor;
class Status;
class Input;
}
class Batch;

class DNN
{
public:
    DNN();
    ~DNN();
    /// access to the currently avaialable global instance of the DNN
    /// this allows accessing the model with DNN::instance()->....
    static DNN *instance() {
        assert(mInstance!=nullptr);
        return mInstance; }

    bool setup();

    /// DNN main function: execute the DNN inference for the
    /// examples provided in 'batch'.
    bool run(Batch *batch);

private:
    static DNN *mInstance;
    // logging
    std::shared_ptr<spdlog::logger> lg;

    // DNN specifics
    bool mDummyDNN; ///< if true, then the tensorflow components are not really used (for debug builds)
    tensorflow::Status getTopClasses(const tensorflow::Tensor &classes, const int n_top, tensorflow::Tensor *indices, tensorflow::Tensor *scores);
    tensorflow::Session *session;
    tensorflow::Session *top_k_session;
    tensorflow::Input *output_classes;
    tensorflow::Tensor *output_time;
    tensorflow::Tensor *top_k_tensor;

    /// select randomly an index 0..n-1, with values the weights.
    int chooseProbabilisticIndex(float *values, int n);


};

#endif // DNN_H
