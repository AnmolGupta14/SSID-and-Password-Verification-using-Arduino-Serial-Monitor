int led1=13,led2=12,buzzer=11; //Pin Declaration 
String ssid,password;
void setup() {
  pinMode(13,OUTPUT); //selecting output mode for pin 13
  pinMode(12,OUTPUT); //selecting output mode for pin 12
  pinMode(11,OUTPUT); //selecting output mode for pin 11
  Serial.begin(9600); //selecting baud rate
  ssid=id(); //calling function to save ssid
  password=ps(); // calling function to save password

}
String id() // this functin will return the value of entered ssid
{
  Serial.print("Enter ssid: ");
  check:
  char ch=Serial.read(); //read the first character
  if(ch=='*') //string is saved only if followed by *
  {
    String str=Serial.readString(); //read the string
    Serial.print('\n');
    Serial.print("Entered SSID is: ");
    Serial.println(str);
    return str;
     
  }
  else
  {
    goto check;
  }
  
}
String ps() // this functin will return the value of entered password
{
  Serial.print("Enter Password: ");
  check:
  char ch=Serial.read(); //read the first character
  if(ch=='*') //string is saved only if followed by *
  {
    String str=Serial.readString(); //read the string
    Serial.print('\n');
    Serial.print("Entered Password is: ");
    Serial.println(str);
    Serial.println("Enter ID for verification: ");
    return str;
     
  }
  else
  {
    goto check;
  }
  
}


void loop()// compare the saved value of ssid and password with new entered values
{
  if(Serial.available())
  {
  Serial.print("Entered SSID for your verification: ");
  String str=Serial.readString();
  Serial.println(str);
  if( str==ssid  )
  {
    
   Serial.println("ID is Correct");
   {
    Serial.print("Enter Password for your verification: ");
    String a=Serial.readString();
    Serial.print('\n');
    Serial.print("Entered password for your verification: ");
    Serial.print(a);
    Serial.print('\n');
    if( a==password  ) // loop to blink green led and buzzer if both id and password is correct
    {
   
     
     Serial.print("Password is Correct");
     digitalWrite(led1,HIGH);
     digitalWrite(led2,LOW);
     digitalWrite(buzzer,HIGH);
     delay(250);
     digitalWrite(buzzer,LOW);
     delay(50);
     digitalWrite(buzzer,HIGH);
     delay(250);
     digitalWrite(buzzer,LOW);
    }
        else if(a!=password) // loop to blink red led and buzzer if password is incorrect
  {
    
    digitalWrite(led2,HIGH);
    digitalWrite(buzzer,HIGH);
    digitalWrite(led1,LOW);
    delay(1000);
    digitalWrite(buzzer,LOW);
    Serial.print('\n');
    Serial.println("Password is InCorrect");
    
  }
    
    }
     }     
     else if(str!=ssid) // loop to blink red led and buzzer if id is incorrect
  {
   
    digitalWrite(led2,HIGH);
    digitalWrite(buzzer,HIGH);
    digitalWrite(led1,LOW);
    delay(1000);
    digitalWrite(buzzer,LOW);
    Serial.println("ID is InCorrect");
    
  }
  
  }
}
