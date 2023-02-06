<?php
    session_start();
    $id   = $_GET["id"];

    $con = mysqli_connect("localhost", "user1", "12345", "sample");
    $sql = "delete from members where id = '$id'";
    mysqli_query($con, $sql);
    mysqli_close($con);

    unset($_SESSION["userid"]);
    unset($_SESSION["username"]);
    unset($_SESSION["userlevel"]);
    unset($_SESSION["userpoint"]);
    echo "

	     <script>
         alert('회원탈퇴 하셨습니다.');
	         location.href = 'index.php';
	     </script>
	   ";
?>
