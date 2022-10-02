#include <iostream>
#include <fstream>
#include <map>

/* ========================================================================== */

/*Задача 3:
	Необходимо реализовать тип данных MessageType который будет содержать в себе тип сообщения для клиента (system, server, session).
	Необходимо реализовать возможность преоброзования текстового формата в MessageType и обратно. 
	Тип данных будет использоваться для обмена сообщениями между клиентом и сервером через API. */

/* ========================================================================== */

// enum Tag {
//     System,
//     Server,
//     Session
// };

// enum TagPos {
//     start,
//     end
// };

class MessageType {
    std::string system;
    std::string server;
    std::string session;
    //std::string tags[3] = {{"{System:}", "{/System}"}, {"{Server:}", "{/Server}"}, {"{Session:}", "{/Session}"}};
public:
    void convertTextToMessageType(std::string text) {
        std::cout << text << std::endl;
        int sm1 = 0, sm2 = 0;
        sm1 = text.find("{System:}"); // позиция тэга "{System:}"
        sm2 = text.find("{/System}"); // позиция тэга "{/System}"
        // sm1=text.find(tags[Tag::System][TagPos::start]); // позиция тэга "{System:}"
        // sm2=text.find(tags[Tag::System][TagPos::end]); // позиция тэга "{/System}"
        this->system =text.substr((sm1 + 9), sm2-sm1-9);
        std::cout << this->system << std::endl;
            
        int sr1 = 0, sr2 = 0;
        sr1 = text.find("{Server:}"); // позиция тэга "{Server:}"
        sr2 = text.find("{/Server}"); // позиция тэга "{/Server}"
        // sm1=text.find(tags[Tag::Server][TagPos::start]); // позиция тэга "{Server:}"
        // sm2=text.find(tags[Tag::Server][TagPos::end]); // позиция тэга "{/Server}"
        this->server =text.substr((sr1 + 9), sr2-sr1-9);
        std::cout << this->server << std::endl;
            
        int sn1 = 0, sn2 = 0;
        sn1 = text.find("{Session:}"); // позиция тэга "{Session:}"
        sn2 = text.find("{/Session}"); // позиция тэга "{/Session}"
        // sm1=text.find(tags[Tag::Session][TagPos::start]); // позиция тэга "{Session:}"
        // sm2=text.find(tags[Tag::Session][TagPos::end]); // позиция тэга "{/Session}"
        this->session = text.substr((sn1 + 10), sn2-sn1-10);
        std::cout << this->session << std::endl;
    }
    std::string convertMessageTypeToText(MessageType msgType) {
        std::string text;
        text = "{System:}"+this->system+"{/System}";
        text += "{Server:}"+this->server+"{/Server}";
        text += "{Session:}"+this->session+"{/Session}";
        return text;
    }
    MessageType() = default;
    ~MessageType() = default;
};

/* ========================================================================== */

class FileReader {
    std::string filePath;
public:
    FileReader(std::string pathToFile) {
        this->filePath = pathToFile;
    }
    std::string getTextFromFile() {
        std::string text;
        std::string line;
        std::fstream in(this->filePath);
        if (in.is_open())
        {
            while (getline(in, line))
            {
                std::cout<<line;
                text.append(line);
            }
        } else {
            std::cout<<"Can't open file"<<std::endl;
        }
        in.close();
        return text;
    }
    ~FileReader() = default;
};

/* ========================================================================== */

/* Пусть текст сообщения будет представлена внутри определенных тегов, например(см. ниже)
{System:}
This is system!
{/System}
{Server:}
192.41.23.53
{/Server}
{Session:}
This is session
{/Session}
*/

/* ========================================================================== */

int main()
{
    FileReader msgFile("./msgText");
    MessageType mt;
    mt.convertTextToMessageType(msgFile.getTextFromFile());
    std::cout << mt.convertMessageTypeToText(mt) << std::endl; 
    // {System:}This is system!{/System}{Server:}192.41.23.53{/Server}{Session:}This is session{/Session}
    
    // далее мы можем передать это сообщение стороннему АПИ(ну или делать с ним все что угодно)
    
    return EXIT_SUCCESS;
}

/* ========================================================================== */