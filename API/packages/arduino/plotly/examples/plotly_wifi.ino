#include <plotlydev.h>
#include <WiFi.h>

char ssid[] = "my_wifi_network"; //  your network SSID (name) 
char pass[] = "my_wifi_password"; // // your network password
int status = WL_IDLE_STATUS;     // the Wifi radio's status
IPAddress server(54,234,232,180);   // plotly's IP

void wifi_connect(){
  // attempt to connect using WPA2 encryption:
  Serial.println("Attempting to connect to WPA network...");
  status = WiFi.begin(ssid, pass);

  // if you're not connected, stop here:
  if ( status != WL_CONNECTED) { 
    Serial.println("Couldn't get a wifi connection");
  while(true);
  } 
  // if you are connected, print out info about the connection:
  else {
    Serial.println("Connected to network");
  }
}

void setup() {
  // initialize serial:
  Serial.begin(9600);

  wifi_connect();

  plotly plotly;
  String filename = "arduino data"; 
  String username = "anna.lyst";    // your plotly username 
  String api_key = "s45sadk4";      // your plotly api_key. display your api_key on the api docs page: https://plot.ly/api

  int i; int j; 
  int N = 30; // N number of points in each burst of data to plotly. Your graph will be updated after transmitting N points
  int Nburst = 10; // number of bursts.

  for(i=0; i<Nburst; i++){
    plotly.open_stream(N, filename, username, api_key); // (re)start connection to plotly
    for(j=0; j<N; j++){
        plotly.post(analogRead(3)); // send data to plotly
        delay(500);
    }
    // after transmitting N points, Plotly creates a graph of this data in your account
    // each burst of data extends the trace of the plot by N points. 
    delay(500);
  }
        
}
void loop(){}
