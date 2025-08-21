import java.util.Scanner;

//Google에서 제공하는 코드로 변경 불가
class GoogleAPI {
    public String run(String context) {
        // (생략) API 호출 후 반환 소스코드...
        return "google data...";
    }
};

//Bing에서 제공하는 코드로 변경 불가
class BingAPI {
    public String go(String context) {
        // (생략) API 호출 후 반환 소스코드...
        return "bing data...";
    }
};

//Yahoo에서 제공하는 코드로 변경 불가
class YahooAPI {
    public String api(String context) {
        // (생략) API 호출 후 반환 소스코드...
        return "yahoo data...";
    }
};

//추론 Library이며 코드 변경 불가
class Inferencer {
    public String inference(String modelName, String context) {
        // (생략)모델 추론
        return "OH! Long time no see!";
    }
};

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int hangle; //0 : 한글, 1 : 영어

        String origin_input;
        int origin_cnt;

        System.out.print("무엇이든지 물어보세요 : ");
        String line = sc.nextLine();

        int price = 0;

        int flag = 0;
        int cnt = 0;
        for (int i = 0; i < line.length(); i++) {
            int ch = line.charAt(i);
            if (ch > 127 || ch < 0) {
                flag = 1;
            }

            if (line.charAt(i) == ' ') continue;
            cnt++;
        }

        origin_input = line;

        origin_cnt = cnt;

        if (flag == 1) hangle = 0;
        else hangle = 1;

        System.out.println("\n사용할 검색엔진의 번호를 입력하세요.");
        System.out.println("1. Google");
        System.out.println("2. Bing");
        System.out.println("3. Yahoo");

        System.out.print("================\n입력 : ");
        int input1 = sc.nextInt();
        System.out.println();

        if (input1 == 1) price += (30 * origin_cnt);
        else if (input1 == 2) price += (20 * origin_cnt);
        else if (input1 == 3) price += (15 * origin_cnt);

        if (input1 == 1) {
            if (origin_cnt < 10) {
                price = 50 * origin_cnt;
            }
        } else if (input1 == 2) {
            if (origin_cnt <= 30) {
                price /= 2;
            }
        }

        //2. 검색엔진 API
        GoogleAPI t1 = new GoogleAPI();
        BingAPI t2 = new BingAPI();
        YahooAPI t3 = new YahooAPI();

        String r1 = t1.run(origin_input);
        String r2 = t2.go(origin_input);
        String r3 = t3.api(origin_input);

        String result = "";
        if (input1 == 1) result = r1;
        else if (input1 == 2) result = r2;
        else if (input1 == 3) result = r3;

        System.out.println("사용할 모델의 번호를 입력하세요.");

        if (hangle == 0) {
            System.out.println("1. GPT");
            System.out.println("2. Gemini");
            System.out.println("3. Llama");
        } else {
            System.out.println("1. Llama");
        }
        System.out.print("================\n입력 : ");

        int input = sc.nextInt();
        System.out.println();

        cnt = origin_cnt;
        if (hangle == 0) {
            if (input == 1) {
                if (cnt > 20) {
                    price += 1000;
                    price += (cnt * 50);
                } else {
                    price += 1000;
                    price += (cnt * 100);
                }
            }
            if (input == 2) {
                if (cnt >= 100) {
                    price += 100;
                    price += (cnt * 120);
                } else {
                    price += 100;
                    price += (cnt * 150);
                }
            }

            if (input == 3) {
                price += cnt * 130;
            }
        } else {
            if (input == 1) {
                price += cnt * 90;
            }
        }

        Inferencer model = new Inferencer();

        //관련 검색어와 함께 모델에 추론시키기
        String result2;
        if (hangle == 0 && input == 1) {
            result2 = model.inference("GPT", result + " " + line);
        } else if (hangle == 0 && input == 2) {
            result2 = model.inference("Gemini", result + " " + line);
        } else if (hangle == 0 && input == 3) {
            result2 = model.inference("Llama", result + " " + line);
        } else if (hangle == 1 && input == 1) {
            result2 = model.inference("Llama", result + " " + line);
        } else {
            System.out.println("ERROR :: 유효하지 않은 입력입니다.");
            return;
        }

        if (input1 < 1 || input1 > 3) {
            System.out.println("ERROR :: 존재하지 않는 검색엔진입니다.");
            return;
        }

        System.out.println("추론결과\n==============================");
        System.out.println(result2);
        System.out.println("Total Price : " + price);
    }
}
