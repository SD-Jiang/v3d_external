#ifndef V3DR_COMMUNICATOR_H
#define V3DR_COMMUNICATOR_H

#include <QWidget>
#include <QtGui>
//#include <QtCore/QCoreApplication>
#include <QTcpSocket>
#include"../3drenderer/v3dr_common.h"
//#include <QRegExpValidator>
//#ifdef _WIN32
//    #include <windows.h>
//#endif

#include "../basic_c_fun/v3d_interface.h"



class FileSocket_send:public QTcpSocket
{
    Q_OBJECT
public:
    explicit FileSocket_send::FileSocket_send
    (QString ip,QString port,QString anofile_path,QObject *parent=0);

    void sendFile(QString filepath,QString filename);
public slots:
    void readMSG();
private:
    QString anopath;
    QString anoname;
};
//class CMainApplication;
class My4DImage;
class MainWindow;
class ManageSocket:public QTcpSocket
{
	Q_OBJECT
public:
	explicit ManageSocket(QObject *parent=0);
	QString ip;
	QString manageport;
	QString name;
    QString loadfile_name;

public slots:
    void onReadyRead();
    void send(QListWidgetItem*);

protected:

signals:
    void makeMessageSocket(QString ip,QString port,QString username);
private:
    QString messageport;


};



class V3dR_Communicator : public QWidget
{
    Q_OBJECT

public:
    explicit V3dR_Communicator(bool *client_flag = 0, V_NeuronSWC_list* ntlist=0);
    ~V3dR_Communicator();
    void onReadySend(QString send_MSG);
//	bool SendLoginRequest();
	//void StartVRScene(QList<NeuronTree>* ntlist, My4DImage *i4d, MainWindow *pmain,bool isLinkSuccess);
	//void Update3DViewNTList(QString &msg, int type);
	void UpdateSendPoolNTList(V_NeuronSWC seg);
	void Collaborationsendmessage();
	void Collaborationaskmessage();
	//trans func
	QString V_NeuronSWCToSendMSG(V_NeuronSWC seg);
	void MsgToV_NeuronSWC(QString msg);

//	ManageSocket * managesocket;

public slots:
    bool SendLoginRequest(QString ip,QString port,QString username);
	//void RunVRMainloop();
	//void SendHMDPosition();
	void CollaborationMainloop();
private slots:
	
    void onReadyRead();
    void onConnected();
    void onDisconnected();
private:
	
    QTcpSocket* socket;
	QString userName;
	QString vr_Port;
	bool CURRENT_DATA_IS_SENT;
	bool * clienton;
	V_NeuronSWC_list * NTList_SendPool;	
	vector<vector<XYZ>> loc_ReceivePool;
	int NTNumReceieved;
	int NTNumcurrentUser;
    quint64 nextblocksize;
};




#endif // V3DR_COMMUNICATOR_H
