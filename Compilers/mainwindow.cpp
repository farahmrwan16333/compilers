#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

#include <cstring>
#include <string>
#include "Parse.h"
#include "Scan.h"
#include "Tree.h"

void MainWindow::on_actionNew_triggered()
{
    ui->input->setText("");
}


int counter = 1;

int MainWindow::drawNode(Node* node, string &str, int id) {
    int edge;

    if(node->key.type == "READ"|| node->key.type == "ASSIGN"){
        str += "node[shape = rect label=\"" + node->key.type+"\n(" + node->key.value + ")\"]id" + to_string(id)+" ";
    }

    if (node->key.type == "IF" || node->key.type == "WRITE" || node->key.type == "REPEAT" ) {
        str += "node[shape = rect label=\"" + node->key.type + "\"]id" + to_string(id)+" ";
    }
    else {
        str += "node[shape = oval label=\"" + node->key.type +"\n(" + node->key.value + ")\"]id" + to_string(id)+" ";
    }

    for (int i = 0; i < (int) node->child.size(); i++) {
        counter++;
        edge = drawNode(node->child[i], str, counter);
        str += "id" + to_string(id) + "--id" + to_string(edge)+" ";
        node->child[i]->key.id = edge;
        qDebug() << QString::number(node->key.id);
    }

    if (node->key.type == "IF") {
         Node* temp, *temp2;
        for (int i = 0; i < (int) node->child.size() - 1; i++) {
            if (node->child[i]->sibling != nullptr) {
                temp = node->child[i]->sibling;
                temp2 = node->child[i + 1];
                str += "{rank = same; id" + to_string(temp->key.id) + "; id" + to_string(temp2->key.id) + "; }" + " id" + to_string(temp->key.id) + "--id" + to_string(temp2->key.id)+" [style = invis]; ";
            }
        }
    }


    for (int i = 0; i < (int) node->child.size() - 1; i++) {
        Node* temp, *temp2;
        if (node->child.size() != 1 && node->child.size() != 0 && node->sibling == nullptr) {
            temp = node->child[i];
            temp2 = node->child[i + 1];
            str += "{rank = same; id" + to_string(temp->key.id) + "; id" + to_string(temp2->key.id) + "; }" + " id" + to_string(temp->key.id) + "--id" + to_string(temp2->key.id)+" [style = invis]; ";
        }
    }
    if (node->sibling != nullptr) {
        counter++;
        edge = drawNode(node->sibling, str, counter);
        str += "{rank = same; id" + to_string(id) + "; id" + to_string(edge) + "; }" + " id" + to_string(id) + "--id" + to_string(edge)+" ";
        node->sibling->key.id = edge;
    }
    return id;
}

void MainWindow::draw(Node* tree) {
    Agraph_t* G;
    GVC_t* gvc;
    gvc = gvContext();
    string dotLang="graph main{";
    drawNode(tree->child[0], dotLang, 1);
    dotLang += "}";
    qDebug()<<QString::fromStdString(dotLang);
    char * y= &dotLang[0];
    G = agmemread(y);
    gvLayout (gvc, G, "dot");
    QString path = QDir::currentPath()+"/parse_tree.png";
    QByteArray ba = path.toLocal8Bit();
    const char *c_str2 = ba.data();
    qDebug() << path;
    gvRenderFilename(gvc,G,"png",c_str2);
    gvFreeLayout(gvc, G);
    agclose (G);
    gvFreeContext(gvc);
}
void MainWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Open the file","",tr("text files (*.txt)"));
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"Error","file not open");
        return;

    }

    QTextStream in(&file);
    QString text=in.readAll();
    ui->input->setPlainText(text);
    file.close();


}
queue<Token> result;
queue<Token> scanner;
string output = "";
void scan()
{
    while (!(scanner.empty())) {

        output += scanner.front().type + "\t" + scanner.front().value + "\n";

        scanner.pop();


    }

}

void MainWindow::on_resetButton_clicked()
{
    ui->input->clear();
    ui->output->clear();
    ui->tree->clear();
}
bool flag = false;

void MainWindow::on_scanButton_clicked()
{
   ui->output->clear();
   string input="";
   output = "";
   input= ui->input->toPlainText().toStdString();


    scanner = scanning(input);

    while (!(scanner.empty())) {

        output += scanner.front().type + "\t" + scanner.front().value + "\n";

        scanner.pop();


    }
    ui->output->setPlainText(QString::fromStdString(output));
    output ="";
}


void MainWindow::on_parseButton_clicked()
{

    string input = ui->input->toPlainText().toStdString();
    //scan(input);
    flag = true;
    result = scanning(input);

    scanner = result;
    output ="";
    if (!result.empty() && result.front().type == "Error") {
        QMessageBox::warning(this,"Error","Syntax Error");
        flag = true;
        return;

    }


    Node* root = program(&result);

    if(root->child.size()){
            draw(root);
            QString path = QDir::currentPath()+"/parse_tree.png";
            QByteArray ba = path.toLocal8Bit();
            const char *c_str2 = ba.data();
            QPixmap *myPixMap = new QPixmap(c_str2);
            ui->tree->setPixmap(*myPixMap);
            ui->tree->setScaledContents(true);
            ui->tree->show();
            scan();
            ui->output->setPlainText(QString::fromStdString(output));

            delete root;


        }
        else{
            QMessageBox::warning(this,"Error","Syntax Error");
            flag = true;
            delete root;
        }
    }




