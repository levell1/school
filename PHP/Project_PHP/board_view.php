<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Post-IT</title>
<link rel="shortcut icon" href="./img/post-it.png"/>
<link rel="stylesheet" type="text/css" href="./css/common.css">
<link rel="stylesheet" type="text/css" href="./css/board.css">
<link rel="stylesheet" type="text/css" href="./css/comment.css">
</head>
<body>

<header>
    <?php include "header.php";?>
</header>
<section>

   	<div id="board_box">
	    <h3 class="title">
			게시판 > 내용보기
		</h3>
<?php
	$num  = $_GET["num"];
	$page  = $_GET["page"];

	$con = mysqli_connect("localhost", "user1", "12345", "sample");
  mysqli_set_charset($con,"utf8");
	$sql = "select * from board where num=$num";
	$result = mysqli_query($con, $sql);

	$row = mysqli_fetch_array($result);
	$id      = $row["id"];
	$name      = $row["name"];
	$regist_day = $row["regist_day"];
	$subject    = $row["subject"];
	$content    = $row["content"];
	$file_name    = $row["file_name"];
	$file_type    = $row["file_type"];
	$file_copied  = $row["file_copied"];
	$hit          = $row["hit"];

  $sub1=$subject.$regist_day;

	$content = str_replace(" ", "&nbsp;", $content);
	$content = str_replace("\n", "<br>", $content);

	$new_hit = $hit + 1;
	$sql = "update board set hit=$new_hit where num=$num";
	mysqli_query($con, $sql);
?>
	    <ul id="view_content">
			<li>
				<span class="col1"><b>제목 :</b> <?=$subject?></span>
				<span class="col2"><?=$name?> | <?=$regist_day?></span>


			</li>
			<li>
				<?php
					if($file_name) {
						$real_name = $file_copied;
						$file_path = "./data/".$real_name;
						$file_size = filesize($file_path);



                  }

                  if($file_type=="image/jpg"||$file_type=="image/jpeg"||$file_type=="image/png"||$file_type=="image/gif"||$file_type=="image/bmp")
                  {
                    $file_path = "./data/".$real_name;
                    echo "<img src='$file_path'alt=''/><br><br>";
                  }
				?>




				<?=$content?>

			</li>

	    </ul>
      <form method="post" name="form" >
      <ul id="comment_view">
			<li>
        <input type="hidden" name="date" value="<?=$regist_day?>">
        <input type="hidden" name="user" value="<?=$userid?>">
				<span class="col1"><b>댓글 :</b> </span>
        <span class="col2"><input style="width: 500px;" type="text" name="content" placeholder="댓글 입력해주세요"></span>
        <span class="col3"><button  type="submit"  onclick="javascript: form.action='comment_insert.php?sub=<?=$subject?>'">입력</button></span>
      </li>
      <li>
        <span class="col1">번호</span>
        <span class="col1">아이디</span>
        <span class="col2">내용</a></span>
      </li>
    </form>
      <?php
      $sql = "select * from comment where sub= '$sub1' order by num desc";
    	$result = mysqli_query($con, $sql);
    	$total_record = mysqli_num_rows($result);

    	$number = $total_record;

       while ($row = mysqli_fetch_array($result))
       {
        $num         = $row["num"];
        $sub     = $row["sub"];
    	  $user          = $row["user"];
    	  $content        = $row["content"];


    ?>

    		<li>
    		  <span class="col1"><?=$number?></span>
    			<span class="col1"><?=$user?></span>
    			<span class="col2"><?=$content?></a></span>
    		</li>

    <?php
       	   $number--;
       }
    ?>
	    </ul>
	    <ul class="buttons">
				<li><button onclick="location.href='board_list.php?page=<?=$page?>'">목록</button></li>
		</ul>

	</div>
</section>
<footer>
    <?php include "footer.php";?>
</footer>
</body>
</html>
