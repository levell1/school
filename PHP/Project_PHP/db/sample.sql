-- phpMyAdmin SQL Dump
-- version 4.9.0.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- 생성 시간: 19-11-24 04:23
-- 서버 버전: 10.4.6-MariaDB
-- PHP 버전: 7.3.8

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- 데이터베이스: `sample`
--

-- --------------------------------------------------------

--
-- 테이블 구조 `board`
--

CREATE TABLE `board` (
  `num` int(11) NOT NULL,
  `id` char(15) NOT NULL,
  `name` char(10) NOT NULL,
  `subject` char(200) NOT NULL,
  `content` text NOT NULL,
  `regist_day` char(30) NOT NULL,
  `hit` int(11) NOT NULL,
  `file_name` char(40) DEFAULT NULL,
  `file_type` char(40) DEFAULT NULL,
  `file_copied` char(40) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 테이블의 덤프 데이터 `board`
--

INSERT INTO `board` (`num`, `id`, `name`, `subject`, `content`, `regist_day`, `hit`, `file_name`, `file_type`, `file_copied`) VALUES
(61, 'levell', '김종욱', '123', '123', '2019-11-18 (03:38:43)', 7, '', '', ''),
(72, 'php123', 'PHP', '안녕하세요', '안녕하세요', '2019-11-18 (04:12:24)', 12, '', '', ''),
(73, 'whddnr0317', '김종욱', '112333', '123123213', '2019-11-21 (06:34:33)', 14, 'intro1.jpg', 'image/jpeg', 'intro12019_11_21_06_34_33.jpg'),
(74, 'whddnr0317', '김종욱', 'ASD', 'ASD', '2019-11-21 (06:41:26)', 9, '', '', ''),
(75, 'wlsdud123', '박진영', '역시 아이유', '아이유 신곡좋습니다 ! ', '2019-11-23 (08:11:14)', 11, 'iu.jpg', 'image/jpeg', 'iu2019_11_23_08_11_14.jpg'),
(76, 'php123', 'PHP', '가구너무 좋네요', '너무 싸고 좋네요', '2019-11-23 (08:26:30)', 3, 'product2_3.jpg', 'image/jpeg', 'product2_32019_11_23_08_26_30.jpg'),
(77, 'php123', 'PHP', '게시판 예제', '게시판 예제', '2019-11-23 (08:28:36)', 0, '', '', ''),
(78, 'php123', 'PHP', '게시판 예제12', '112', '2019-11-23 (08:28:41)', 1, '', '', ''),
(79, 'php123', 'PHP', '게시판 예제', '213123', '2019-11-23 (08:28:45)', 2, '', '', ''),
(80, 'php123', 'PHP', '123', '1232', '2019-11-23 (08:28:49)', 5, '', '', ''),
(81, 'levell', '김종욱', '안녕하세요', '테스트\r\n', '2019-11-24 (03:27:03)', 1, '600.jpg', 'image/jpeg', '6002019_11_24_03_27_03.jpg');

-- --------------------------------------------------------

--
-- 테이블 구조 `comment`
--

CREATE TABLE `comment` (
  `num` int(11) NOT NULL,
  `sub` varchar(50) NOT NULL,
  `user` varchar(20) NOT NULL,
  `content` varchar(100) NOT NULL,
  `date` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 테이블의 덤프 데이터 `comment`
--

INSERT INTO `comment` (`num`, `sub`, `user`, `content`, `date`) VALUES
(58, '안녕하세요2019-11-18 (04:12:24)', 'php123', '123123', '2019-11-18 (04:20:21)'),
(59, '안녕하세요2019-11-18 (04:12:24)', 'whddnr0317', 'ASD', '2019-11-21 (06:29:26)'),
(60, '1123332019-11-21 (06:34:33)', 'whddnr0317', '123123', '2019-11-21 (06:34:37)'),
(63, '1123332019-11-21 (06:34:33)', 'whddnr0317', 'ASD', '2019-11-21 (06:41:28)'),
(64, '역시 아이유2019-11-23 (08:11:14)', 'levell', '?????', '2019-11-23 (08:11:28)'),
(65, 'ASD2019-11-21 (06:41:26)', 'levell', '댓글 ', '2019-11-23 (08:11:40)'),
(66, '1232019-11-18 (03:38:43)', 'levell', '123', '2019-11-23 (08:11:51)'),
(67, '역시 아이유2019-11-23 (08:11:14)', 'wlsdud123', '누구세요 ?', '2019-11-23 (08:11:51)'),
(69, '가구너무 좋네요2019-11-23 (08:26:30)', 'php123', 'ㅇㅇㅇㅇ', '2019-11-23 (08:28:15)'),
(70, '게시판 예제2019-11-23 (08:28:45)', 'php123', '댓글', '2019-11-23 (08:29:39)'),
(71, '1232019-11-23 (08:28:49)', 'PHP111', '댓글', '2019-11-23 (10:33:22)'),
(72, '1123332019-11-21 (06:34:33)', 'levell', '안녕하세요', '2019-11-24 (03:26:33)');

-- --------------------------------------------------------

--
-- 테이블 구조 `friend`
--

CREATE TABLE `friend` (
  `num` int(11) NOT NULL,
  `name` char(20) NOT NULL,
  `tel` char(20) NOT NULL,
  `address` char(80) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 테이블의 덤프 데이터 `friend`
--

INSERT INTO `friend` (`num`, `name`, `tel`, `address`) VALUES
(1, '송예진', '031-123-4567', '경기도 용인시 수지구 정평로 30'),
(2, '김수정', '031-333-4444', '양평군 지평면 묵방길 123번지');

-- --------------------------------------------------------

--
-- 테이블 구조 `members`
--

CREATE TABLE `members` (
  `num` int(11) NOT NULL,
  `id` char(15) NOT NULL,
  `pass` char(15) NOT NULL,
  `name` char(10) NOT NULL,
  `email` char(80) DEFAULT NULL,
  `regist_day` char(20) DEFAULT NULL,
  `level` int(11) DEFAULT NULL,
  `point` int(11) DEFAULT NULL,
  `addr` char(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 테이블의 덤프 데이터 `members`
--

INSERT INTO `members` (`num`, `id`, `pass`, `name`, `email`, `regist_day`, `level`, `point`, `addr`) VALUES
(22, 'levell', 'last0317', '김종욱', 'whddnr0317@naver.com', '2019-10-07 (05:18)', 1, 45540, '12123'),
(31, 'Test11', '123123', '테스트', 'whddnr0317@naver.com', '2019-11-18 (01:05)', 9, 2000, '123'),
(32, 'php123', 'php123', 'PHP', '123@naver.com', '2019-11-18 (04:10)', 9, 150, '주소'),
(33, 'PHP111', '1', 'PHP', 'PHP@naver.com', '2019-11-21 (08:12)', 1, 98000, 'PHP'),
(36, 'wlsdud123', 'wlsdud12', '박진영', 'YNC2@naver.com', '2019-11-23 (08:09)', 9, 10, '영남이공대'),
(37, 'goe0317', '123123', '김민지', 'goe0317@naver.com', '2019-11-24 (03:13)', 9, 2893500, '아러아');

-- --------------------------------------------------------

--
-- 테이블 구조 `message`
--

CREATE TABLE `message` (
  `num` int(11) NOT NULL,
  `send_id` char(20) NOT NULL,
  `rv_id` char(20) NOT NULL,
  `subject` char(200) NOT NULL,
  `content` text NOT NULL,
  `regist_day` char(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 테이블의 덤프 데이터 `message`
--

INSERT INTO `message` (`num`, `send_id`, `rv_id`, `subject`, `content`, `regist_day`) VALUES
(1, 'levell', '123123', '123123', '123123', '2019-10-21 (04:04)'),
(2, 'levell', '123123', '123', '123', '2019-10-21 (04:10)'),
(3, 'levell', '123123', '2323', '2323', '2019-10-21 (04:10)'),
(4, 'levell', 'levell', '434', '33434', '2019-10-21 (04:10)'),
(5, 'levell', 'levell', '123123', '12312', '2019-10-21 (04:13)'),
(6, 'levell', 'whddnr0317', 'qq', 'qq', '2019-10-21 (04:17)'),
(7, 'levell', 'levell', 'RE: qq', '\r\n\r\n-----------------------------------------------\r\n&gt; qq', '2019-10-21 (04:20)');

-- --------------------------------------------------------

--
-- 테이블 구조 `orderlist`
--

CREATE TABLE `orderlist` (
  `num` int(10) NOT NULL,
  `name` varchar(20) NOT NULL,
  `filename` varchar(50) NOT NULL,
  `price` int(10) NOT NULL,
  `amount` int(3) NOT NULL,
  `totalprice` int(10) NOT NULL,
  `userid` varchar(10) NOT NULL,
  `gubon` varchar(10) NOT NULL,
  `state` varchar(10) NOT NULL DEFAULT '대기'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 테이블의 덤프 데이터 `orderlist`
--

INSERT INTO `orderlist` (`num`, `name`, `filename`, `price`, `amount`, `totalprice`, `userid`, `gubon`, `state`) VALUES
(63, '포스트 잇', 'data/main111_17_08_20.jpg', 2000, 1, 2000, 'php123', '주문', '대기'),
(66, '다용도 책상', 'data/main211_17_08_32.jpg', 12000, 1, 12000, 'php123', '장바구니', '대기'),
(68, '포스트 잇', 'data/main111_17_08_20.jpg', 2000, 1, 2000, 'php123', '장바구니', '대기'),
(123, '다용도 책상', 'data/main211_17_08_32.jpg', 12000, 1, 12000, 'levell', '주문', '대기'),
(144, '다용도 책상', 'data/main211_17_08_32.jpg', 12000, 2, 24000, 'whddnr0317', '주문', '주문확정'),
(145, '아아아', 'data/intro211_17_10_04.jpg', 1000, 1, 1000, 'whddnr0317', '주문', '대기'),
(149, '간단 수납장', 'data/product2_311_21_07_32.jpg', 40000, 1, 40000, 'levell', '주문', '대기'),
(150, '포스트 잇', 'data/main111_17_08_20.jpg', 3000, 1, 3000, 'levell', '주문', '주문확정'),
(151, '포스트 잇', 'data/main111_17_08_20.jpg', 3000, 1, 3000, 'levell', '주문', '주문확정'),
(153, '포스트 잇', 'data/main111_17_08_20.jpg', 3000, 3, 9000, 'levell', '주문', '대기'),
(154, '다용도 책상', 'data/main211_17_08_32.jpg', 12000, 1, 12000, 'levell', '주문', '주문확정'),
(159, '아아아', 'data/intro211_17_10_04.jpg', 1000, 1, 1000, 'levell', '주문', '대기'),
(160, '아아아', 'data/intro211_17_10_04.jpg', 1000, 1, 1000, 'levell', '주문', '대기'),
(166, '아아아', 'data/intro211_17_10_04.jpg', 1000, 1, 1000, 'goe0317', '주문', '대기');

-- --------------------------------------------------------

--
-- 테이블 구조 `store`
--

CREATE TABLE `store` (
  `num` int(3) NOT NULL,
  `kind` varchar(20) DEFAULT NULL,
  `name` varchar(20) NOT NULL,
  `price` int(7) NOT NULL,
  `filename` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 테이블의 덤프 데이터 `store`
--

INSERT INTO `store` (`num`, `kind`, `name`, `price`, `filename`) VALUES
(1, '문구', '포스트 잇', 4000, 'main111_17_08_20.jpg'),
(2, '문구', '다용도 책상', 12000, 'main211_17_08_32.jpg'),
(45, '퀼트제품', '아아아', 1000, 'intro211_17_10_04.jpg'),
(46, '기타', '제품3', 100000, 'intro111_18_01_13.jpg'),
(47, '문구', '딱풀', 500, 'product311_21_07_27.jpg'),
(48, '문구', '미니수첩', 1500, 'product411_21_07_27.jpg'),
(49, '문구', '라이언세트', 5000, 'product111_21_07_27.jpg'),
(50, '문구', '롱수첩', 2000, 'product211_21_07_28.jpg'),
(51, '기타', '파랑수납장', 70000, 'product2_111_21_07_31.jpg'),
(52, '기타', '간단 수납장', 40000, 'product2_311_21_07_32.jpg'),
(53, '기타', '목재 수납장', 40000, 'product2_211_21_07_33.jpg'),
(54, '퀼트제품', '테스트', 50000, '60011_24_03_25.jpg');

-- --------------------------------------------------------

--
-- 테이블 구조 `worker`
--

CREATE TABLE `worker` (
  `num` int(11) NOT NULL,
  `id` char(20) NOT NULL,
  `name` char(10) NOT NULL,
  `gender` char(1) NOT NULL,
  `age` int(11) DEFAULT NULL,
  `department` char(20) NOT NULL,
  `phone` char(20) NOT NULL,
  `address` char(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 테이블의 덤프 데이터 `worker`
--

INSERT INTO `worker` (`num`, `id`, `name`, `gender`, `age`, `department`, `phone`, `address`) VALUES
(1, 'chkim', '김창훈', 'M', NULL, '총무부', '010-3838-8577', '경기도 용신시'),
(3, 'jek98', '안달훈', 'M', 25, '인사부', '010-3744-4747', '강원도 정선군'),
(5, 'apple3', '김소영', 'F', 52, '총무부', '010-2845-8978', '전라남도 순천시'),
(6, 'sub093', '김수정', 'M', 53, '홍보부', '010-3834-1248', '경상북도 상주시'),
(7, 'chulsu', '김철수', 'M', 10, '홍보부', '010-1235-3788', '경기도 오산시'),
(8, 'yckim', '김영철', 'M', 32, '인사부', '010-2222-3333', '경기도 용인시'),
(9, 'yerin99', '김예린', 'F', 25, '총무부', '010-7777-9999', '서울시 강서구'),
(10, 'sjjung', '정수정', 'F', 35, '경리부', '010-3636-3563', '충청남도 아산시'),
(11, 'tuttle7', '이예린', 'F', 21, '연구소', '010-3756-9823', '경기도 성남시');

--
-- 덤프된 테이블의 인덱스
--

--
-- 테이블의 인덱스 `board`
--
ALTER TABLE `board`
  ADD PRIMARY KEY (`num`);

--
-- 테이블의 인덱스 `comment`
--
ALTER TABLE `comment`
  ADD PRIMARY KEY (`num`);

--
-- 테이블의 인덱스 `friend`
--
ALTER TABLE `friend`
  ADD PRIMARY KEY (`num`);

--
-- 테이블의 인덱스 `members`
--
ALTER TABLE `members`
  ADD PRIMARY KEY (`num`);

--
-- 테이블의 인덱스 `message`
--
ALTER TABLE `message`
  ADD PRIMARY KEY (`num`);

--
-- 테이블의 인덱스 `orderlist`
--
ALTER TABLE `orderlist`
  ADD PRIMARY KEY (`num`);

--
-- 테이블의 인덱스 `store`
--
ALTER TABLE `store`
  ADD PRIMARY KEY (`num`);

--
-- 테이블의 인덱스 `worker`
--
ALTER TABLE `worker`
  ADD PRIMARY KEY (`num`);

--
-- 덤프된 테이블의 AUTO_INCREMENT
--

--
-- 테이블의 AUTO_INCREMENT `board`
--
ALTER TABLE `board`
  MODIFY `num` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=82;

--
-- 테이블의 AUTO_INCREMENT `comment`
--
ALTER TABLE `comment`
  MODIFY `num` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=73;

--
-- 테이블의 AUTO_INCREMENT `friend`
--
ALTER TABLE `friend`
  MODIFY `num` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- 테이블의 AUTO_INCREMENT `members`
--
ALTER TABLE `members`
  MODIFY `num` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=38;

--
-- 테이블의 AUTO_INCREMENT `message`
--
ALTER TABLE `message`
  MODIFY `num` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- 테이블의 AUTO_INCREMENT `orderlist`
--
ALTER TABLE `orderlist`
  MODIFY `num` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=167;

--
-- 테이블의 AUTO_INCREMENT `store`
--
ALTER TABLE `store`
  MODIFY `num` int(3) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=55;

--
-- 테이블의 AUTO_INCREMENT `worker`
--
ALTER TABLE `worker`
  MODIFY `num` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
