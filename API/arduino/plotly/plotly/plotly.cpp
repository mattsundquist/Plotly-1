#include "Arduino.h"
#include <WiFi.h>
#include <plotly.h>


plotly::plotly(){
	VERBOSE = true;
}

void plotly::open_stream(int N, String filename, String username, String api_key){
	_ni = 0; // number of integers transmitted
    _N = N;  // number of integers in a burst
    _nChar = 0; // number of characters transmitted

    if(VERBOSE) Serial.println("connecting to server");
	char server[] = "plot.ly";
	while ( !client.connect(server, 80) ) {
			if(VERBOSE) Serial.println("couldn\'t connect to server. trying again.");
			delay(1000);
		}

    if(VERBOSE) Serial.println("connected to server");

    // HTTP Meta
    client.println("POST /clientresp HTTP/1.1");
    client.println("Host: 107.21.214.199"); 
    client.println("User-Agent: Arduino/1.0");
    
    // compute an upper bound on the post body size
    header = "version=0.2&origin=plot&platform=arduino&un=";
    header += username;
    header += "&key=";
    header += api_key;
    header += "&kwargs={\"filename\": \"";
    header += filename;
    header += "\", \"fileopt\": \"extend\"}&args=[{\"y\": [" ;
   	_upper = header.length() + N*2 + N*6 + 3 - 2; // header length + 2-chars for comma and space for each number  + 6 chars for the largest int (-32767) + 3 for termination chars: ]}] - 2 since the last nubmer doesnt have a comma
	
	
	s = "Content-Length: "; 
	s += _upper;
    client.println(s);

    // start printing the body
    client.println();
    client.print(header);
    _nChar += header.length();
}

void plotly::post(int data){
    _ni += 1;				// number of data elements
    if(_ni == _N){			// i.e. the last number
    	close_stream(data);
    }
    else{
		s = "";
	    s = s + data + ", ";
	    _nChar += s.length();	// number of chars
	    client.print(s);
    }
    return;
}


void plotly::close_stream(int data){
	s = "";
	s = s + data + "]}]";
	client.print(s);

	_nChar += s.length();

	// fill the remainder of the post with white space
	for(i=_nChar; i<_upper; i++){
		client.print(" ");
	}
	// final newline to terminate the post
	client.println();
	client.stop();
	if(VERBOSE) Serial.println("closed connection with server");
	return;
}
