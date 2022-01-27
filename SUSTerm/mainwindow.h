#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**************************************************************************************************/

#include <QMainWindow>
#include <QTextBrowser>
#include <QDialog>
#include <QSize>
#include <QScrollBar>
#include <QKeyEvent>
#include <QDateTime>
#include <QTimer>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QKeyEvent>
#include <QRegExp>

#include "ui_mainwindow.h"
#include "constants.h"

/**************************************************************************************************/

enum terminal_modes { ASCII = 0, HEX = 1, ASCII_HEX = 2 };

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private:
        Ui::MainWindow *ui;
        QSerialPort *serial_port;
        QTimer *qtimer_serial_ports;
        QStringList qstrl_available_serial_ports;
        QStringList qstrl_send_history;
        int send_history_i;
        bool timestamp_on;
        bool timestamp_ms;
        terminal_modes terminal_mode;
        int current_slider_pos_v, current_slider_pos_h;

        void SerialPortsChecks_timer_init(void);
        void OpenPort(void);
        void ClosePort(void);

        void PrintReceivedData(QTextBrowser* textBrowser0, QTextBrowser *textBrowser1,
                               terminal_modes mode);
        QString GetActualSystemTime(void);

        QRegExp rx_parse;
        QString fhver;
        QString cvoice;
        QString u2diag;
        QString imei;
        QString nck;
        bool isInfoPressed = false;
        int counter_parser = 0;;

        QString lock_status;

        void delay(int ms);

    private slots:
        void SerialSend(QString qstr_to_send);
        void SerialPortsCheck(void);
        void ButtonOpenPressed(void);
        void ButtonClosePressed(void);
        void ButtonClearPressed(void);
        void ButtonSendPressed(void);
        void SerialReceive(void);
        void CBoxBaudsChanged(void);
        void CBoxEOLChanged(void);
        void CheckBoxAutoScrollToggled(void);
        bool eventFilter(QObject *target, QEvent *event);
        void SerialPortErrorHandler(void);
        void MenuBarExitClick(void);
        void MenuBarTermAsciiClick(void);
        void MenuBarTermHexClick(void);
        void MenuBarTermBothAsciiHexClick(void);
        void MenuBarTimestampClick(void);
        void MenuBarTimestampMsClick(void);
        void MenuBarAboutClick(void);
        void UnlockModem();
        void getAllInfo();
        void ParseAllInfo(QString qstr_to_parse);
        QByteArray ConvertToHEX(QByteArray data);
};

/**************************************************************************************************/

#endif // MAINWINDOW_H
