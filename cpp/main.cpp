#include <iostream>
#include <string>

using namespace std;

int hangle;
//0 : 한글
//1 : 영어


class LycosCralwer {
public:
	std::string run() {
		// (생략)크롤링 후 데이터 반환 소스코드...
		// 변경이 잦은 코드
		return "lycos data...";
	}
};

class YahooCralwer {
public:
	std::string run() {
		// (생략)크롤링 후 데이터 반환 소스코드...
		// 변경이 잦은 코드
		return "yahoo data...";
	}
};

class GoogleAPI {
public:
	std::string api() {
		// (생략)API 호출 후 반환 소스코드...
		return "google data...";
	}
};

class NaverAPI {
public:
	std::string runAPI() {
		// (생략)API 호출 후 반환 소스코드...
		return "naver data...";
	}
};

class KakaoAPI {
public:
	std::string go() {
		// (생략)API 호출 후 반환 소스코드...
		return "kakao data...";
	}
};

class DBConnector {
public:
	void dbInit() {
		// (생략)db 연결 코드...
	}

	void saveQuery(string site, string data) {
		// (생략)db에 문자열 저장...
	}
	
	string loadQuery(string context) {
		// (생략)db에 관련 문자열 가져오기
		return "result";
	}

	void dbDisconnect() {
		// (생략)db 접속종료...
	}
};

class Inferencer {
public:
	string inference(string modelName, string context) {
		// (생략)모델 추론
		return "OH! Long time no see!";
	}
};

int main() {
	
	cout << "무엇이든지 물어보세요 : ";
	char buf[256];
	cin.getline(buf, 255);
	string line(buf);

	int price = 0;

	int flag = 0;
	int cnt = 0;
	for (int i = 0; i < line.size(); i++) {
		if (line[i] > 127) {
			flag = 1;
		}

		if (line[i] == ' ') continue;
		cnt++;
	}

	price = cnt * 100;

	if (flag == 1) hangle = 0;
	else hangle = 1;

	cout << "\n사용할 검색엔진의 번호를 입력하세요.\n";
	cout << "1. Lycos\n";
	cout << "2. Yahoo\n";
	cout << "3. Google\n";
	cout << "4. Naver\n";
	cout << "5. Kakao\n";

	cout << "================\n입력 : ";
	int input1;
	cin >> input1;
	cout << "\n";

	if (input1 == 1) price += 1000;
	else if (input1 == 2) price += 1000;
	else if (input1 == 3) price += 300;
	else if (input1 == 4) price += 200;
	else if (input1 == 5) price += 100;

	//1. 크롤링 해야하는 검색엔진
	LycosCralwer t1;
	YahooCralwer t2;

	//2. 검색엔진 API
	GoogleAPI t3;
	NaverAPI t4;
	KakaoAPI t5;

	string r1 = t1.run();
	string r2 = t2.run();
	string r3 = t3.api();
	string r4 = t4.runAPI();
	string r5 = t5.go();

	string result = "";
	if (input1 == 1) result = r1;
	else if (input1 == 2) result = r2;
	else if (input1 == 3) result = r3;
	else if (input1 == 4) result = r4;
	else if (input1 == 5) result = r5;

	DBConnector db;

	db.dbInit();

	if (input1 == 1) db.saveQuery("Lycos", r1);
	else if (input1 == 2) db.saveQuery("Yahoo", r2);
	else if (input1 == 3) db.saveQuery("Google", r3);
	else if (input1 == 4) db.saveQuery("Naver", r4);
	else if (input1 == 5) db.saveQuery("Kakao", r5);

	db.dbDisconnect();

	cout << "사용할 모델의 번호를 입력하세요.\n";

	if (hangle == 0) {
		cout << "1. GPT\n";
		cout << "2. Gemini\n";
		cout << "3. claude\n";
		cout << "4. DeepSeek\n";
		cout << "5. Llama\n";
	}
	else {
		cout << "1. DeepSeek\n";
		cout << "2. Llama\n";
	}
	cout << "================\n입력 : ";

	int input;
	cin >> input;
	cout << "\n";
	if (hangle == 0) {
		if (input == 1) price += 500;
		if (input == 2) price += 400;
		if (input == 3) price += 300;
		if (input == 4) price += 100;
		if (input == 5) price += 100;
	}
	else {
		if (input == 1) price += 100;
		if (input == 2) price += 100;
	}

	Inferencer model;

	//DB에서 관련 검색어 가져오기
	string db1 = db.loadQuery(line);

	//관련 검색어와 함께 모델에 추론시키기
	string result2;
	if (hangle == 0 && input == 1) {
		result2 = model.inference("GPT", db1 + " " + line);
	}
	else if (hangle == 0 && input == 2) {
		result2 = model.inference("Gemini", db1 + " " + line);
	}
	
	else if (hangle == 0 && input == 3) {
		result2 = model.inference("claude", db1 + " " + line);
	}

	
	else if (hangle == 0 && input == 4) {
		result2 = model.inference("DeepSeek", db1 + " " + line);
	}

	
	else if (hangle == 0 && input == 5) {
		result2 = model.inference("Llama", db1 + " " + line);
	}

	
	else if (hangle == 1 && input == 1) {
		result2 = model.inference("DeepSeek", db1 + " " + line);
	}

	
	else if (hangle == 1 && input == 2) {
		result2 = model.inference("Llama", db1 + " " + line);
	}
	else {
		std::cout << "ERROR :: 유효하지 않은 입력입니다.\n";
		return 0;
	}

	if (input1 < 1 || input1 > 5) {
		std::cout << "ERROR :: 존재하지 않는 검색엔진입니다.\n";
	}

	cout << "추론결과\n==============================\n";
	cout << result2 << "\n";
	cout << "Total Price : " << price << "\n";

	return 0;
}
