//-------------------PAGINA DE CONFIGURACION--------------------
void paginaconf() {
  server.send(200, "text/html", pagina + mensaje + paginafin);
}
//--------------------MODO_CONFIGURACION------------------------
void modoconf() {
  delay(3000);
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);

  WiFi.softAP(ssidConf, passConf);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("IP del acces point: ");
  tft.setCursor(0, 0, 2);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(1);
  tft.println("SSID: FFREND");
  tft.print("IP: ");
  tft.println(WiFi.softAPIP().toString());
  Serial.println(myIP);
  Serial.println("WebServer iniciado...");

  server.on("/", paginaconf); //esta es la pagina de configuracion

  server.on("/guardar_conf", guardar_conf); //Graba en la eeprom la configuracion

  server.on("/escanear", escanear); //Escanean las redes wifi disponibles

  server.begin();

  while (true) {
    server.handleClient();
  }
}

//---------------------GUARDAR CONFIGURACION-------------------------
void guardar_conf() {

  Serial.println(server.arg("ssid"));//Recibimos los valores que envia por GET el formulario web
  grabar(0, server.arg("ssid"));
  Serial.println(server.arg("pass"));
  grabar(50, server.arg("pass"));

  mensaje = "Configuracion Guardada...";
  paginaconf();
  ESP.restart();
}
