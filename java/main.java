import java.util.Scanner;

class LycosCralwer {
    public String run() {
        return "lycos data...";
    }
}

class YahooCralwer {
    public String run() {
        return "yahoo data...";
    }
}

class GoogleAPI {
    public String api() {
        return "google data...";
    }
}

class NaverAPI {
    public String runAPI() {
        return "naver data...";
    }
}

class KakaoAPI {
    public String go() {
        return "kakao data...";
    }
}

class DBConnector {
    public void dbInit() { /* db 연결 */ }
    public void saveQuery(String site, String data) { /* db 저장 */ }
    public String loadQuery(String context) { return "result"; }
    public void dbDisconnect() { /* db 접속 종료 */ }
}

class Inferencer {
    public String inference(String modelName, String context) {
        return "OH! Long time no see!";
    }
}

public class Main {
    static int hangle; // 0 : 한글, 1 : 영어

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("무엇이든지 물어보세요 : ");
        String line = sc.nextLine();

        int price = 0;
        int flag = 0;
        int cnt = 0;
        for (char ch : line.toCharArray()) {
            if (ch > 127) flag = 1;
            if (ch == ' ') continue;
            cnt++;
        }
        price = cnt * 100;

        if (flag == 1) hangle = 0;
        else hangle = 1;

        System.out.println("\n사용할 검색엔진의 번호를 입력하세요.");
        System.out.println("1. Lycos");
        System.out.println("2. Yahoo");
        System.out.println("3. Google");
        System.out.println("4. Naver");
        System.out.println("5. Kakao");
        System.out.println("================\n입력 : ");
        int input1 = Integer.parseInt(sc.nextLine());
        System.out.println();

        if (input1 == 1) price += 1000;
        else if (input1 == 2) price += 1000;
        else if (input1 == 3) price += 300;
        else if (input1 == 4) price += 200;
        else if (input1 == 5) price += 100;

        // 1. 크롤링 엔진
        LycosCralwer t1 = new LycosCralwer();
        YahooCralwer t2 = new YahooCralwer();

        // 2. API 엔진
        GoogleAPI t3 = new GoogleAPI();
        NaverAPI t4 = new NaverAPI();
        KakaoAPI t5 = new KakaoAPI();

        String r1 = t1.run();
        String r2 = t2.run();
        String r3 = t3.api();
        String r4 = t4.runAPI();
        String r5 = t5.go();

        String result = "";
        if (input1 == 1) result = r1;
        else if (input1 == 2) result = r2;
        else if (input1 == 3) result = r3;
        else if (input1 == 4) result = r4;
        else if (input1 == 5) result = r5;

        DBConnector db = new DBConnector();
        db.dbInit();

        if (input1 == 1) db.saveQuery("Lycos", r1);
        else if (input1 == 2) db.saveQuery("Yahoo", r2);
        else if (input1 == 3) db.saveQuery("Google", r3);
        else if (input1 == 4) db.saveQuery("Naver", r4);
        else if (input1 == 5) db.saveQuery("Kakao", r5);

        db.dbDisconnect();

        System.out.println("사용할 모델의 번호를 입력하세요.");
        if (hangle == 0) {
            System.out.println("1. GPT");
            System.out.println("2. Gemini");
            System.out.println("3. Clade");
            System.out.println("4. DeepSeek");
            System.out.println("5. Llama");
        } else {
            System.out.println("1. DeepSeek");
            System.out.println("2. Llama");
        }
        System.out.println("================\n입력 : ");
        int input = Integer.parseInt(sc.nextLine());
        System.out.println();

        if (hangle == 0) {
            if (input == 1) price += 500;
            if (input == 2) price += 400;
            if (input == 3) price += 300;
            if (input == 4) price += 100;
            if (input == 5) price += 100;
        } else {
            if (input == 1) price += 100;
            if (input == 2) price += 100;
        }

        Inferencer model = new Inferencer();

        // DB에서 관련 검색어 가져오기
        String db1 = db.loadQuery(line);

        // 관련 검색어와 함께 모델에 추론시키기
        String result2;
        if (hangle == 0 && input == 1) {
            result2 = model.inference("GPT", db1 + " " + line);
        } else if (hangle == 0 && input == 2) {
            result2 = model.inference("Gemini", db1 + " " + line);
        } else if (hangle == 0 && input == 3) {
            result2 = model.inference("Clade", db1 + " " + line);
        } else if (hangle == 0 && input == 4) {
            result2 = model.inference("DeepSeek", db1 + " " + line);
        } else if (hangle == 0 && input == 5) {
            result2 = model.inference("Llama", db1 + " " + line);
        } else if (hangle == 1 && input == 1) {
            result2 = model.inference("DeepSeek", db1 + " " + line);
        } else if (hangle == 1 && input == 2) {
            result2 = model.inference("Llama", db1 + " " + line);
        } else {
            System.out.println("ERROR :: 유효하지 않은 입력입니다.");
            return;
        }

        if (input1 < 1 || input1 > 5) {
            System.out.println("ERROR :: 존재하지 않는 검색엔진입니다.");
        }

        System.out.println("추론결과\n==============================");
        System.out.println(result2);
        System.out.println("Total Price : " + price);
    }
}
