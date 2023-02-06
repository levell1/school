-- phpMyAdmin SQL Dump
-- version 4.9.0.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- 생성 시간: 19-10-28 01:18
-- 서버 버전: 10.4.6-MariaDB
-- PHP 버전: 7.3.9

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
  `regist_day` char(20) NOT NULL,
  `hit` int(11) NOT NULL,
  `file_name` char(40) DEFAULT NULL,
  `file_type` char(40) DEFAULT NULL,
  `file_copied` char(40) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 테이블의 덤프 데이터 `board`
--

INSERT INTO `board` (`num`, `id`, `name`, `subject`, `content`, `regist_day`, `hit`, `file_name`, `file_type`, `file_copied`) VALUES
(1, 'dldlsahr', '???', 'ã…ã„´ã…‡ã„¹', 'ã…ã„´ã…‡ã„¹', '2019-10-28 (01:15)', 9, 'message.sql', 'application/octet-stream', '2019_10_28_01_15_59.sql'),
(2, 'ttt', 'ì¡°ì •í˜„z', '10ì›” ë§ˆì§€ë§‰ì£¼', 'ì´ë²ˆì£¼ë§Œ ì§€ë‚˜ë©´ ì¼ë…„ë„ ë‘ë‹¬ ë‚¨ì•˜ë‹¤.\r\nì‹œê°„ ì°¸ ë¹ ë¥´ë‹¤.', '2019-10-28 (01:16)', 3, '', '', ''),
(3, 'abcd', 'aaa', 'aaa', 'aaa', '2019-10-28 (01:16)', 0, '', '', ''),
(4, 'aaa', 'aaa', 'ì°¸ ì¢‹ì€ &#039;ê°€ì„&#039;ìž…ë‹ˆë‹¤.', 'ì°¸ ì¢‹ì€ &#039;ê°€ì„&#039;ìž…ë‹ˆë‹¤.', '2019-10-28 (01:16)', 6, '', '', ''),
(5, '12345', '???', '12345', '12345', '2019-10-28 (01:16)', 1, '', '', ''),
(6, 'zn', 'zn', '.', '.', '2019-10-28 (01:16)', 1, '', '', ''),
(7, 'ckwogur', '???', 'ê°€ìž…í–ˆì–´ìš”~', 'í•˜í•«', '2019-10-28 (01:16)', 3, '', '', ''),
(8, 'NIE', 'nem', 'ë‹¤ëžŒì¥', 'ë§ˆì‹¯ë‹¤', '2019-10-28 (01:16)', 3, '', '', ''),
(9, 'tmdwns', 'tmdwns', '.', '.', '2019-10-28 (01:17)', 1, '', '', ''),
(10, 'Null', '???', 'null', 'null', '2019-10-28 (01:17)', 1, '', '', ''),
(11, 'KDH1', '???', 'ì•ˆë…•í•˜ì„¸ìš”', '^^', '2019-10-28 (01:17)', 1, '', '', ''),
(12, 'monkaS', 'm', 'test', 'test', '2019-10-28 (01:17)', 1, '', '', ''),
(13, 'wlsdud12', '???', 'ë“±ì—…ì‹ ì²­', 'ì¢‹ì€ì•„ì¹¨ìž…ë‹ˆë‹¤', '2019-10-28 (01:17)', 2, '', '', ''),
(14, 'sincerely', '???', 'PHPìˆ˜ì—…', '1234', '2019-10-28 (01:17)', 5, '', '', ''),
(15, 'choi', '???', 'zzzzzzz', 'í…ŒìŠ¤íŠ¸í…ŒìŠ¤íŠ¸', '2019-10-28 (01:17)', 2, '', '', ''),
(16, 'patrick', '??', 'ì•„ë‹Œë°ìš”~ ëš±ì¸ë°ìš”~', 'ëš±ì¸ë°ìš”~', '2019-10-28 (01:17)', 11, '1.jpg', 'image/jpeg', '2019_10_28_01_17_48.jpg'),
(17, 'alzl63', '???', 'ì•ˆë…•ì´ëž€ë§', 'í—¬ë¡œí—¬ë¡œ ì´ì   êµ¿ë°”ì´êµ¿ë°”ì´', '2019-10-28 (01:18)', 2, '', '', ''),
(18, 'ambition03', '03?', '03ë²ˆ04ë²ˆ', '3w4\r\n4w5\r\n4w3', '2019-10-28 (01:18)', 3, '', '', ''),
(19, '123', '123', '123', '123', '2019-10-28 (01:18)', 0, '', '', ''),
(20, 'k1234', '???', 'PHP', 'PHP', '2019-10-28 (01:18)', 0, '', '', '');

--
-- 덤프된 테이블의 인덱스
--

--
-- 테이블의 인덱스 `board`
--
ALTER TABLE `board`
  ADD PRIMARY KEY (`num`);

--
-- 덤프된 테이블의 AUTO_INCREMENT
--

--
-- 테이블의 AUTO_INCREMENT `board`
--
ALTER TABLE `board`
  MODIFY `num` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=21;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
