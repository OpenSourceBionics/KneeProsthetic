//WRITTEN FOR TEENSY 3.6. WORKS ON BENCHTOP DRILL

//empirically determined speed curve (x = thetaDotDes [rad/s], y = command voltage[rad/s])
#define MOT_CONTROL_CURVE (0.67 - 0.148*log(abs(thetaDotDes))) 
#define MOT_MIN_CMD 2.5

//teensy 3.2 limits
#define DAC_RES 1023 //10 bit
#define DAC_MAX 3.3 //[V]

//motor vars
const int DAC_Pin = A14; //motor speed pin
const int directionPin = 5; 
const int enablePin = 4;
float motCmd; //value to output to motor controller


void setup() {
    Serial.begin(115200);

    pinMode(directionPin, OUTPUT);
    pinMode(DAC_Pin, OUTPUT);
    pinMode(enablePin, OUTPUT);

    digitalWrite(enablePin, LOW);
    delay(200);
    Serial.println("begin");
    delay(1200);
}

void MotorDrive(float thetaDotDes)
{
    if(thetaDotDes >= 0.0)
    {
        digitalWrite(directionPin, HIGH);
    }
    else
    {
        digitalWrite(directionPin, LOW);
    }
    
    digitalWrite(enablePin, HIGH);
    motCmd = MOT_CONTROL_CURVE; //[V]
    motCmd = constrain(motCmd, 0.0, MOT_MIN_CMD); //anything outside of this voltage range cause the controller to pause

    analogWrite(DAC_Pin, (int)(motCmd*DAC_RES/DAC_MAX)); //convert command into voltage
}

void loop() {
    MotorDrive(5);
    Serial.println("move");
    delay(200);
    MotorDrive(0);
    Serial.println("stop");
    digitalWrite(enablePin, LOW);
    delay(200);
}