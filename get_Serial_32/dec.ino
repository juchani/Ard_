String decoder(String d, bool est, int c) {
  String d1 = d;
  int n = d.indexOf(":");
  d1.remove(n - 1, d1.length());

  if (c < 2 && c > 3) {
    d.replace(" ", "");
    //d.replace("\n","");
  }
  if (est == 1) {
    d.remove(0, n + 1);
  }
  if (est == 0) {
    d.remove( n - 1, d.length());
  }

  if (d.indexOf("$@  @")) {
    d.trim();
    //d = "|" + d;
    return d;
  }


}
