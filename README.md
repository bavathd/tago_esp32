# tago_esp32

###  Initialize the tago by adding userdata to tago initialising class <br/>
  **tago tag("xyz-wifi", "the-pass", "YOUR_API_KEY");**<br/>
  *  Create a account in tago.io and verify your e-mail.
  *  Generate a token and paste it in place of **"YOUR_API_KEY"**.
  *  Enter the SSID and Password of your WiFi in place of "xyz-wifi" and "the-pass".

    
### Connect to the wifi network<br/>
  **tag.connectWifi()**<br/>

### Send the sensor data to cloud using the send function<br/>
  **tag.send("enter your variable name", String(your data));**<br/>
