<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>Post-IT</title>
  </head>
  <body>


﻿<?php
    session_start();
    if (isset($_SESSION["userid"])) $userid = $_SESSION["userid"];
    else $userid = "";
    if (isset($_SESSION["username"])) $username = $_SESSION["username"];
    else $username = "";
    if (isset($_SESSION["userlevel"])) $userlevel = $_SESSION["userlevel"];
    else $userlevel = "";
    if (isset($_SESSION["userpoint"])) $userpoint = $_SESSION["userpoint"];
    else $userpoint = "";
?>

        <div id="top">
            <h3>
                <a id="headerLogo" href="index.php" style="font-size: 25px"><span>Post-IT</span>
               </a>
            </h3>
            <form method="post" action="search.php">
            <ul id="top_menu">
<?php
    if(!$userid) {
?>
<li><input type="submit" id="headerLogo" value="검색"></a>
<input style="width:100px;" id="headerLogo" name="search"> </li>
<li><a id="headerLogo" href="shop.php">상점</a> </li>
<li><a id="headerLogo" href="intro.php">소개</a> </li>
<li><a id="headerLogo" href="login_form.php">로그인</a></li>
<li><a id="headerLogo" href="sign_up_form.php">회원가입</a></li>
<li><a id="headerLogo" href="board_list.php">게시판</a></li>

              <?php
    } else {
?>

<li><input type="submit" id="headerLogo" value="검색"></a>
<input style="width:100px;" id="headerLogo" name="search"> </li>

<li><a id="headerLogo" href="shop.php">상점</a> </li>
<li><a id="headerLogo" href="intro.php">소개</a> </li>
<li><a id="headerLogo" href="point.php">포인트 충전</a> </li>
<li><a id="headerLogo" href="information_form.php">정보수정</a></li>
<li><a id="headerLogo" href="cart.php">장바구니</a></li>
<li><a id="headerLogo" href="board_list.php">게시판</a></li>

<?php
    }
?>
<?php
    if($userlevel==1) {
?>
                <li> | </li>
                <li><a id="headerLogo" href="admin.php">관리자 모드</a></li>

                <li><a id="headerLogo" href="admin_order.php">주문관리</a></li>
<?php
}
?>
            </ul>
</form>
        </div>


      </body>
    </html>
