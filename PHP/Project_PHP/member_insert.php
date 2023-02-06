<?php
    $id   = $_POST["id"];
    $pass = $_POST["pass"];
    $name = $_POST["name"];
    $addr = $_POST["addr"];
    $email1  = $_POST["email1"];
    $email2  = $_POST["email2"];
    $email = $email1."@".$email2;
    $regist_day = date("Y-m-d (H:i)");  
    $ipadd=$_SERVER['REMOTE_ADDR'];

    $con = mysqli_connect("localhost", "user1", "12345", "sample");
    mysqli_set_charset($con,"utf8");
	$sql = "insert into members(id, pass, name, email, regist_day, level, point, addr) ";
	$sql .= "values('$id', '$pass', '$name', '$email', '$regist_day', 9, 0, '$addr')";

	mysqli_query($con, $sql);
    mysqli_close($con);

    echo "
	      <script>
	          location.href = 'index.php';
	      </script>
	  ";
?>
