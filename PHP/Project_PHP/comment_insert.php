<?php
session_start();
if (isset($_SESSION["userid"])) $userid = $_SESSION["userid"];
else $userid = "";
if (isset($_SESSION["username"])) $username = $_SESSION["username"];
else $username = "";

if ( !$userid )
{
    echo("
                <script>
                alert('로그인 후 이용해 주세요!');
                history.go(-1)
                </script>
    ");
            exit;
}
    $sub   = $_GET["sub"];
    $user = $_POST["user"];
    $content = $_POST["content"];
    $date = $_POST["date"];
    $regist_day = date("Y-m-d (H:i:s)");
    $subject = $sub.$date;

    $con = mysqli_connect("localhost", "user1", "12345", "sample");
    mysqli_set_charset($con,"utf8");
	  $sql = "insert into comment(sub, user, content, date) ";
	  $sql .= "values('$subject', '$user', '$content', '$regist_day')";

	mysqli_query($con, $sql);
    mysqli_close($con);

    echo "
    <script>
    history.go(-1)
    </script>
	  ";
?>
