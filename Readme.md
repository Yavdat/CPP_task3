Задача 1:
	Дан файл конфигурации коммутатора "test_config.xml", нужно его считать и распарсить, 
	из корневого узла <Ports> вывести на в консоль конфигурацию портов, 
	из корневого узда <Vlans> вывести список значений Vlan по умолчания для данных портов (узел <defVlans>).
	
Задача 2:
	Есть необходимость хранить список удаленных ip-адресов серверов в отдельном txt файле.
	Каждый сервер должен храниться в отдельной строке файла.
	Реализовать три функции:
		GetServersList() – возвращает список серверов из файла;
		AddServer() – добавляет сервер в файл;
		DeleteServer() – удаляет сервер из файла. 
	Сигнатура функций заранее не определена. 
Задача 3:
	Необходимо реализовать тип данных MessageType который будет содержать в себе тип сообщения для клиента (system, server, session).
	Необходимо реализовать возможность преоброзования текстового формата в MessageType и обратно. 
	Тип данных будет использоваться для обмена сообщениями между клиентом и сервером через API. 	