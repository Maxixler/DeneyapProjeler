#define DO  261
#define RE  293
#define MI  329
#define FA  349
#define SOL 392
#define LA  440
#define SI  466

const int buzzerPin = 9;

const int melody[] = {
    LA, RE, FA, MI, RE, FA, RE, MI, RE, SI, DO, LA, LA, RE, FA, MI, RE, FA, RE, MI, RE, SI, LA, SOL, SOL, SI, LA, MI, SOL, SI, LA, RE, RE, FA, DO, SI, LA, DO, SI, SI, LA, LA, LA, RE, LA, RE, FA, MI, RE, FA, RE, MI, RE, SI, DO, LA, LA, RE, FA, MI, RE, FA, RE, MI, RE, SI, LA
};

const int tempo[] = {
    500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 2500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 2500, 500, 500, 500, 2500, 500, 500, 500, 2500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 2500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 2500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500
};

void setup() {
    pinMode(buzzerPin, OUTPUT);
}

void loop() {
    for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
        tone(buzzerPin, melody[i]);
        delay(tempo[i]);
    }
}
