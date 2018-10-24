#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <memory>

#include "modelcontroller.h"
#include "landscapevisualization.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void initiateLogging();
    void initiateModelController();
    ~MainWindow();
private slots:
    void modelStateChanged(QString s);
    void modelUpdate();
    void finishedYear();
    void checkVisualization();

    void on_actionTest_DNN_triggered();

    void on_pbStart_clicked();

    void on_pbStop_clicked();

    void on_run_clicked();

    void on_pushButton_clicked();

    void on_pbTest_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pbLoad_clicked();

    void on_pbDeleteModel_clicked();

    void on_pbRunModel_clicked();

    void on_pbRun_clicked();

    void on_pushButton_5_clicked();

    void on_pbUpdateStats_clicked();

    void on_pbCancel_clicked();

    void on_pbTestTF_clicked();

    void on_pbTestExpre_clicked();

    void on_actioncreate_output_docs_triggered();

    void on_pbTestVis_clicked();

    void on_pbRenderExpression_clicked();

    void on_visState_clicked() { checkVisualization(); }
    void on_visExpression_clicked() {checkVisualization(); }
    void on_visNone_clicked() {checkVisualization(); }

    void on_actionRender_to_file_triggered();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<ModelController> mMC;
    LandscapeVisualization *mLandscapeVis;
    QTimer mUpdateModelTimer;
};

#endif // MAINWINDOW_H
