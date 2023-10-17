<?php 

	error_reporting(E_ALL ^ E_WARNING); 
	include 'var.php';

	$address = '127.0.0.1';
	$port = 5000;

	$server = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
	socket_set_option($server, SOL_SOCKET, SO_REUSEADDR, 1);
	socket_bind($server, $address, $port);
	socket_listen($server);


	$Clients=array(100);

    $client = socket_accept($server);

    $request = socket_read($client, 5000);
    preg_match('#Sec-WebSocket-Key: (.*)\r\n#', $request, $matches);
    $key = base64_encode(pack(
        'H*',
        sha1($matches[1] . '258EAFA5-E914-47DA-95CA-C5AB0DC85B11')
    ));
    $headers = "HTTP/1.1 101 Switching Protocols\r\n";
    $headers .= "Upgrade: websocket\r\n";
    $headers .= "Connection: Upgrade\r\n";
    $headers .= "Sec-WebSocket-Version: 13\r\n";
    $headers .= "Sec-WebSocket-Accept: $key\r\n\r\n";
    socket_write($client, $headers, strlen($headers));

  while (true) {
      $content = 'Now: ' . time() . ' count:'. $GLOBALS['count']++ ;
      $response = chr(129) . chr(strlen($content)) . $content;
  
      if(socket_write($client, $response)){
  
      }
      else{
          echo "ERROR \n";
      }
  
      sleep(1);  
  }
?>
