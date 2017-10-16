#ifndef MODELCONTROLLER_H
#define MODELCONTROLLER_H

#include <QObject>
#include <QThread>
#include "modelshell.h"
#include "modelrunstate.h"


class ToyModelShell; // forward

class ToyModelController : public QObject
{
    Q_OBJECT
    QThread *modelThread;
    QThread *dnnThread;
public:
    explicit ToyModelController(QObject *parent = nullptr);
    ~ToyModelController();

signals:
    void log(const QString &s);

public slots:
    void run();
    void abort();
    void finishedRun();
private:
    ToyModelShell *mModel;

};

class DNNShell; // forward


class ModelController : public QObject
{
    Q_OBJECT
    QThread *modelThread;
    QThread *dnnThread;
public:
    explicit ModelController(QObject *parent = nullptr);
    ~ModelController();
    ModelShell *shell() const { return mModelShell; }
    const Model *model() const { return mModelShell->model(); }
    DNNShell *dnnInterface() const { return mDNNShell; }
    RunState *state() { return mState.get(); }

signals:
    void log(const QString &s);
    void stateChanged(QString s);

    void finishedYear(int n);
    void finished();

public slots:
    void setup(QString fileName);
    void shutdown();

    void run(int n_years);
    //void abort();
    void finishedStep(int n);
private:
    ModelShell *mModelShell; // lives in main thread
    DNNShell *mDNNShell; // lives in DNN thread
    std::unique_ptr<RunState> mState; // the state of the system (lives in main thread)

    int mYearsToRun;
    int mCurrentStep;

};

#endif // MODELCONTROLLER_H
