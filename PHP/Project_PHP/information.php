<?php
    $id = $_GET["id"];

    $pass = $_POST["pass"];
    $name = $_POST["name"];
    $addr = $_POST["addr"];
    $email1  = $_POST["email1"];
    $email2  = $_POST["email2"];

    $email = $email1."@".$email2;

    $con = mysqli_connect("localhost", "user1", "12345", "sample");
    mysqli_set_charset($con,"utf8");
    $sql = "update members set pass='$pass', name='$name' , email='$email', addr='$addr'";
    $sql .= " where id='$id'";
    mysqli_query($con, $sql);

    mysqli_close($con);

    session_start();
    $_SESSION["userid"] = $id;
    $_SESSION["username"] = $name;
    echo "
	      <script>
	          location.href = 'index.php';
	      </script>
	  ";
?>
