#include <iostream>
#include <string>
#include <httplib.h>
#include <nlohmann/json.hpp>


const std::string API = "1c6fbd94f02e0bfa31e590642d42d8b8";


int main() {
	setlocale(LC_ALL, "RUS");
	using json = nlohmann::json;

	std::string city;
	std::cout << "Введите город: ";
	std::cin >> city;

	httplib::Client cli("http://api.openweathermap.org");
	std::string request;
	json data;

	int choice;

	bool flag = true;


	while (flag) {
		std::cout << "1 - Посмотреть погоду."<< std::endl;
		std::cout << "2 - Ввести новый город." << std::endl;
		std::cout << "3 - Выход" << std::endl;
		std::cin >> choice;

		switch (choice) {
		case 1:
			request = "/data/2.5/weather?";
			request += "q=" + city;
			request += "&appid=" + API;
			data = json::parse(cli.Get(request)->body);

			std::cout << "Погода: " << data["weather"][0]["main"] << std::endl;
			std::cout << "Температура: " << data["main"]["temp"] - 273.15 << std::endl;
			break;
		case 2:
			std::cout << "Введите город: ";
			std::cin >> city;
			break;
		case 3:
			flag = false;
			break;

		}
	}

	return 0;
}