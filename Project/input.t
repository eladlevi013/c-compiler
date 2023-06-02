function main():void{
  var i:int;
  var x = 0:int;
  var y = true:bool;
  for(i = 0; i < 10;i = i + 1){
    x = x + 5;
  }

  for (i = 'f';i < 10;i = i + 1)
  {
    x = x + 6;
  }

  for (i = 0; i ;i = i + 1){
    x = x + 7;
  }

  for(i=0;i< 10;i = y)
  {
    x = x + 8;
  }

  for (i = 0;i < 10 && y || false; i = i + 1)
  {
    x = x + 5;
  }
}
