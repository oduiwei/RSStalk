/*
Navicat MySQL Data Transfer

Source Server         : 本地连接
Source Server Version : 50713
Source Host           : localhost:3306
Source Database       : rsstalk

Target Server Type    : MYSQL
Target Server Version : 50713
File Encoding         : 65001

Date: 2016-11-10 10:46:08
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for browser_history
-- ----------------------------
DROP TABLE IF EXISTS `browser_history`;
CREATE TABLE `browser_history` (
  `id` int(10) NOT NULL,
  `url` varchar(150) NOT NULL,
  `date` varchar(150) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of browser_history
-- ----------------------------
INSERT INTO `browser_history` VALUES ('0', 'http://www.baidu.com', '2016-10-26 21:32:18 周三');
INSERT INTO `browser_history` VALUES ('1', 'http://www.baidu.com', '2016-11-05 22:40:49 周六');

-- ----------------------------
-- Table structure for class
-- ----------------------------
DROP TABLE IF EXISTS `class`;
CREATE TABLE `class` (
  `id` int(10) unsigned NOT NULL,
  `name` varchar(40) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of class
-- ----------------------------
INSERT INTO `class` VALUES ('0', '博客订阅');

-- ----------------------------
-- Table structure for contents
-- ----------------------------
DROP TABLE IF EXISTS `contents`;
CREATE TABLE `contents` (
  `id` int(10) unsigned NOT NULL,
  `title` varchar(512) DEFAULT NULL,
  `url` varchar(512) DEFAULT NULL,
  `readstate` int(1) DEFAULT NULL,
  `deleted` tinyint(1) DEFAULT NULL,
  `favorite` tinyint(1) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of contents
-- ----------------------------
INSERT INTO `contents` VALUES ('0', '你的字典里有多少元素？', 'http://blog.zhaojie.me/2014/07/how-many-elements-in-your-dictionary.html', '1', '0', '0');
INSERT INTO `contents` VALUES ('1', '逆泛型执行器', 'http://blog.zhaojie.me/2014/05/zrx-quiz-1-answer.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('2', '.NET程序性能的基本要领', 'http://blog.zhaojie.me/2014/05/essential-dotnet-perf-truths-tips.html', '1', '0', '0');
INSERT INTO `contents` VALUES ('3', '在香港生活的初步感受', 'http://blog.zhaojie.me/2013/09/hongkong-life-first-impression.html', '1', '0', '0');
INSERT INTO `contents` VALUES ('4', '比较下中国大陆和香港之间的个税差异', 'http://blog.zhaojie.me/2013/07/china-hongkong-taxing-comparison.html', '1', '0', '0');
INSERT INTO `contents` VALUES ('5', '抓取InfoQ内容的calibre脚本', 'http://blog.zhaojie.me/2013/06/calibre-recipe-infoq.html', '1', '0', '0');
INSERT INTO `contents` VALUES ('6', '使用calibre抓取2013年的MSDN Magazine', 'http://blog.zhaojie.me/2013/06/calibre-recipe-for-msdn-magazine-2013.html', '1', '0', '0');
INSERT INTO `contents` VALUES ('7', '防止装箱落实到底，只做一半也是失败', 'http://blog.zhaojie.me/2013/04/dont-go-half-way-of-preventing-boxing.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('8', '为什么我不喜欢Go语言式的接口（即Structural Typing）', 'http://blog.zhaojie.me/2013/04/why-i-dont-like-go-style-interface-or-structural-typing.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('9', '为什么我认为goroutine和channel是把别的平台上类库的功能内置在语言里', 'http://blog.zhaojie.me/2013/04/why-channel-and-goroutine-in-golang-are-buildin-libraries-for-other-platforms.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('10', '如何在不装箱的前提下调用“显式”实现的接口方法？（答案）', 'http://blog.zhaojie.me/2013/04/how-to-call-explicitly-implemented-interface-method-without-boxing-answer.html', '1', '0', '0');
INSERT INTO `contents` VALUES ('11', '如何在不装箱的前提下调用“显式实现”的接口方法？', 'http://blog.zhaojie.me/2013/03/how-to-call-explicitly-implemented-interface-method-without-boxing.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('12', '针对struct对象使用using关键字是否会引起装箱？', 'http://blog.zhaojie.me/2013/03/using-on-disposable-struct-will-box-or-not.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('13', '串与绳（1）：.NET与Java里的String类型', 'http://blog.zhaojie.me/2013/03/string-and-rope-1-string-in-dotnet-and-java.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('14', 'Everpage：将Evernote的笔记展现在页面上', 'http://blog.zhaojie.me/2013/03/everpage-load-and-display-notes-from-evernote-on-the-page.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('15', '真是O(1)吗？想清楚了没？', 'http://blog.zhaojie.me/2013/01/think-in-detail-why-its-o-1.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('16', '一个最基本的HashedLinkedList', 'http://blog.zhaojie.me/2013/01/a-basic-hashed-linked-list.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('17', '阅读.NET源代码那些事', 'http://blog.zhaojie.me/2013/01/reading-dotnet-source-code.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('18', 'NullableKey：解决Dictionary中键不能为null的问题', 'http://blog.zhaojie.me/2012/12/nullablekey-nullable-key-in-dictionary.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('19', '不同泛型参数区分的独立类型', 'http://blog.zhaojie.me/2012/12/isolated-types-by-different-generic-type-arguments.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('20', '如何读懂并写出装逼的函数式代码', 'http://coolshell.cn/articles/17524.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('21', '什么是工程师文化？', 'http://coolshell.cn/articles/17497.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('22', '关于高可用的系统', 'http://coolshell.cn/articles/17459.html', '1', '0', '0');
INSERT INTO `contents` VALUES ('23', '这多年来我一直在钻研的技术', 'http://coolshell.cn/articles/17446.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('24', '缓存更新的套路', 'http://coolshell.cn/articles/17416.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('25', '为什么我不在微信公众号上写文章', 'http://coolshell.cn/articles/17391.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('26', '性能测试应该怎么做？', 'http://coolshell.cn/articles/17381.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('27', '让我们来谈谈分工', 'http://coolshell.cn/articles/17295.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('28', 'Cuckoo Filter：设计与实现', 'http://coolshell.cn/articles/17225.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('29', 'Docker基础技术：DeviceMapper', 'http://coolshell.cn/articles/17200.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('30', 'Docker基础技术：AUFS', 'http://coolshell.cn/articles/17061.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('31', 'Docker基础技术：Linux CGroup', 'http://coolshell.cn/articles/17049.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('32', 'Docker基础技术：Linux Namespace（上）', 'http://coolshell.cn/articles/17010.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('33', 'Docker基础技术：Linux Namespace（下）', 'http://coolshell.cn/articles/17029.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('34', '关于移动端的钓鱼式攻击', 'http://coolshell.cn/articles/17066.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('35', '如何生成一段Typoglycemia文本（解答）', 'http://blog.zhaojie.me/2012/11/how-to-generate-typoglycemia-text-result.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('36', '如何生成一段Typoglycemia文本？', 'http://blog.zhaojie.me/2012/11/how-to-generate-typoglycemia-text.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('37', '如何让您的事件支持逆变', 'http://blog.zhaojie.me/2012/11/how-to-make-your-event-support-contravariance.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('38', '为List<T>内部添加一个“删除多个元素”的方法', 'http://blog.zhaojie.me/2012/11/add-a-remove-multiple-method-for-list.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('39', '图灵访谈之三十六：以“玩”之名——赵劼（老赵）专访', 'http://blog.zhaojie.me/2012/10/interview-by-turing.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('40', '讨论：一则并行聚合计算方案的设计', 'http://blog.zhaojie.me/2012/09/discussion-design-of-a-parallel-aggregation-case.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('41', '我看面试时出（纯）算法题', 'http://blog.zhaojie.me/2012/08/my-opinion-of-algorithm-interview.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('42', '由eval生成的代码效率真的很差吗？', 'http://blog.zhaojie.me/2012/08/js-code-from-eval-benchmark.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('43', '我对“语言之争”的看法：别随便拉我入场', 'http://blog.zhaojie.me/2012/08/programming-languages-arguments-dont-pull-me-in.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('44', '写给《程序员》杂志社：那些你们早该知道的东西', 'http://blog.zhaojie.me/2012/07/to-programmer-magazine-something-you-should-have-known-for-a-long-time.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('45', '专访Jscex作者老赵（上）：缘由、思路及发展', 'http://blog.zhaojie.me/2012/07/infoq-interview-jscex-author-1.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('46', 'Jscex与Promise/A那些事', 'http://blog.zhaojie.me/2012/06/promise-support-in-jscex.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('47', '使用Node.js编写Shell脚本，暨Jscex 0.6.5版本发布', 'http://blog.zhaojie.me/2012/06/nodejs-shell-jscex-0.6.5.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('48', '两年多来第二次更新博客功能', 'http://blog.zhaojie.me/2012/06/the-second-blog-feature-during-the-past-two-years.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('49', 'Jscex单元测试：喝着咖啡品着茶', 'http://blog.zhaojie.me/2012/06/jscex-unit-tests-with-mocha-chai.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('50', 'Jscex预编译器及其DocPad插件', 'http://blog.zhaojie.me/2012/06/jscex-pre-complier-and-docpad-plugin.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('51', 'Jscex疯狂周末', 'http://blog.zhaojie.me/2012/06/jscex-weekend.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('52', 'C#的设计缺陷（2）：不能以void作为泛型参数', 'http://blog.zhaojie.me/2012/05/csharp-design-flaws-2-cannot-use-void-as-generic-type-parameter.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('53', 'C#的设计缺陷（1）：显式实现接口内的事件', 'http://blog.zhaojie.me/2012/05/csharp-design-flaws-1-explicitly-implement-interface-event.html', '0', '0', '0');
INSERT INTO `contents` VALUES ('54', '编写一个“绑定友好”的WPF控件', 'http://blog.zhaojie.me/2012/05/wpf-binding-friendly-user-control.html', '0', '0', '0');

-- ----------------------------
-- Table structure for delete_feed
-- ----------------------------
DROP TABLE IF EXISTS `delete_feed`;
CREATE TABLE `delete_feed` (
  `id` int(10) unsigned NOT NULL,
  `title` varchar(150) NOT NULL,
  `class_id` int(10) NOT NULL,
  `url` varchar(150) DEFAULT NULL,
  `path` varchar(150) DEFAULT NULL,
  `delete_date` varchar(150) DEFAULT NULL,
  PRIMARY KEY (`id`,`title`,`class_id`),
  KEY `feed_id` (`title`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of delete_feed
-- ----------------------------
INSERT INTO `delete_feed` VALUES ('0', '学院新闻', '1', 'http://www.scjzz.com.cn/rsstalk/group/scuniv/software/01.xml', 'F:/Qt_workplace/RSStalk/RSStalk/build-RSStalk-Desktop_Qt_5_7_0_MSVC2015_64bit-Debug/XML/海胖博客.xml', '2016-11-09 20:54:09 周三');
INSERT INTO `delete_feed` VALUES ('1', '学院新闻', '3', 'http://www.scjzz.com.cn/rsstalk/group/scuniv/computer/01.xml', 'F:/Qt_workplace/RSStalk/RSStalk/build-RSStalk-Desktop_Qt_5_7_0_MSVC2015_64bit-Debug/XML/酷 壳 – CoolShell.cn1.xml', '2016-11-09 20:54:11 周三');
INSERT INTO `delete_feed` VALUES ('1', '招聘信息', '1', 'http://www.scjzz.com.cn/rsstalk/group/scuniv/software/02.xml', 'F:/Qt_workplace/RSStalk/RSStalk/build-RSStalk-Desktop_Qt_5_7_0_MSVC2015_64bit-Debug/XML/风雪之隅.xml', '2016-11-09 20:54:09 周三');
INSERT INTO `delete_feed` VALUES ('1', '招聘信息', '2', 'http://www.scjzz.com.cn/rsstalk/group/scuniv/chemistry/02.xml', 'F:/Qt_workplace/RSStalk/RSStalk/build-RSStalk-Desktop_Qt_5_7_0_MSVC2015_64bit-Debug/XML/四火的唠叨.xml', '2016-11-09 20:54:10 周三');
INSERT INTO `delete_feed` VALUES ('2', '学院新闻', '2', 'http://www.scjzz.com.cn/rsstalk/group/scuniv/chemistry/01.xml', 'F:/Qt_workplace/RSStalk/RSStalk/build-RSStalk-Desktop_Qt_5_7_0_MSVC2015_64bit-Debug/XML/酷 壳 – CoolShell.cn.xml', '2016-11-09 20:54:10 周三');
INSERT INTO `delete_feed` VALUES ('3', '学院新闻', '4', 'http://www.scjzz.com.cn/rsstalk/group/bjuniv/software/01.xml', 'F:/Qt_workplace/RSStalk/RSStalk/build-RSStalk-Desktop_Qt_5_7_0_MSVC2015_64bit-Debug/XML/C++博客-陈硕的Blog.xml', '2016-11-09 20:54:12 周三');
INSERT INTO `delete_feed` VALUES ('3', '招聘信息', '3', 'http://www.scjzz.com.cn/rsstalk/group/scuniv/computer/02.xml', 'F:/Qt_workplace/RSStalk/RSStalk/build-RSStalk-Desktop_Qt_5_7_0_MSVC2015_64bit-Debug/XML/四火的唠叨1.xml', '2016-11-09 20:54:12 周三');
INSERT INTO `delete_feed` VALUES ('4', '学院新闻', '5', 'http://www.scjzz.com.cn/rsstalk/group/qhuniv/software/01.xml', 'F:/Qt_workplace/RSStalk/RSStalk/build-RSStalk-Desktop_Qt_5_7_0_MSVC2015_64bit-Debug/XML/C++博客-陈硕的Blog1.xml', '2016-11-09 20:54:13 周三');
INSERT INTO `delete_feed` VALUES ('4', '招聘信息', '4', 'http://www.scjzz.com.cn/rsstalk/group/bjuniv/software/02.xml', 'F:/Qt_workplace/RSStalk/RSStalk/build-RSStalk-Desktop_Qt_5_7_0_MSVC2015_64bit-Debug/XML/isnowfy.xml', '2016-11-09 20:54:12 周三');
INSERT INTO `delete_feed` VALUES ('5', '招聘信息', '5', 'http://www.scjzz.com.cn/rsstalk/group/qhuniv/software/02.xml', 'F:/Qt_workplace/RSStalk/RSStalk/build-RSStalk-Desktop_Qt_5_7_0_MSVC2015_64bit-Debug/XML/isnowfy1.xml', '2016-11-09 20:54:13 周三');

-- ----------------------------
-- Table structure for feed
-- ----------------------------
DROP TABLE IF EXISTS `feed`;
CREATE TABLE `feed` (
  `feed_id` int(10) unsigned NOT NULL,
  `class_id` int(10) unsigned NOT NULL,
  `title` varchar(512) DEFAULT NULL,
  `create_time` varchar(512) DEFAULT NULL,
  `lastBuildDate` varchar(512) DEFAULT NULL,
  PRIMARY KEY (`feed_id`,`class_id`),
  KEY `id` (`class_id`),
  CONSTRAINT `feed_ibfk_1` FOREIGN KEY (`class_id`) REFERENCES `class` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of feed
-- ----------------------------
INSERT INTO `feed` VALUES ('0', '0', '赵杰', 'new', '2016-10-25 17:47:40 周二');
INSERT INTO `feed` VALUES ('1', '0', '酷壳', 'new', '2016-10-25 17:26:21 周二');

-- ----------------------------
-- Table structure for feed_own_content
-- ----------------------------
DROP TABLE IF EXISTS `feed_own_content`;
CREATE TABLE `feed_own_content` (
  `feed_id` int(10) unsigned NOT NULL,
  `content_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`feed_id`,`content_id`),
  KEY `content_id` (`content_id`),
  CONSTRAINT `feed_own_content_ibfk_1` FOREIGN KEY (`feed_id`) REFERENCES `feed` (`feed_id`),
  CONSTRAINT `feed_own_content_ibfk_2` FOREIGN KEY (`content_id`) REFERENCES `contents` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of feed_own_content
-- ----------------------------
INSERT INTO `feed_own_content` VALUES ('0', '0');
INSERT INTO `feed_own_content` VALUES ('0', '1');
INSERT INTO `feed_own_content` VALUES ('0', '2');
INSERT INTO `feed_own_content` VALUES ('0', '3');
INSERT INTO `feed_own_content` VALUES ('0', '4');
INSERT INTO `feed_own_content` VALUES ('0', '5');
INSERT INTO `feed_own_content` VALUES ('0', '6');
INSERT INTO `feed_own_content` VALUES ('0', '7');
INSERT INTO `feed_own_content` VALUES ('0', '8');
INSERT INTO `feed_own_content` VALUES ('0', '9');
INSERT INTO `feed_own_content` VALUES ('0', '10');
INSERT INTO `feed_own_content` VALUES ('0', '11');
INSERT INTO `feed_own_content` VALUES ('0', '12');
INSERT INTO `feed_own_content` VALUES ('0', '13');
INSERT INTO `feed_own_content` VALUES ('0', '14');
INSERT INTO `feed_own_content` VALUES ('0', '15');
INSERT INTO `feed_own_content` VALUES ('0', '16');
INSERT INTO `feed_own_content` VALUES ('0', '17');
INSERT INTO `feed_own_content` VALUES ('0', '18');
INSERT INTO `feed_own_content` VALUES ('0', '19');
INSERT INTO `feed_own_content` VALUES ('1', '20');
INSERT INTO `feed_own_content` VALUES ('1', '21');
INSERT INTO `feed_own_content` VALUES ('1', '22');
INSERT INTO `feed_own_content` VALUES ('1', '23');
INSERT INTO `feed_own_content` VALUES ('1', '24');
INSERT INTO `feed_own_content` VALUES ('1', '25');
INSERT INTO `feed_own_content` VALUES ('1', '26');
INSERT INTO `feed_own_content` VALUES ('1', '27');
INSERT INTO `feed_own_content` VALUES ('1', '28');
INSERT INTO `feed_own_content` VALUES ('1', '29');
INSERT INTO `feed_own_content` VALUES ('1', '30');
INSERT INTO `feed_own_content` VALUES ('1', '31');
INSERT INTO `feed_own_content` VALUES ('1', '32');
INSERT INTO `feed_own_content` VALUES ('1', '33');
INSERT INTO `feed_own_content` VALUES ('1', '34');
INSERT INTO `feed_own_content` VALUES ('0', '35');
INSERT INTO `feed_own_content` VALUES ('0', '36');
INSERT INTO `feed_own_content` VALUES ('0', '37');
INSERT INTO `feed_own_content` VALUES ('0', '38');
INSERT INTO `feed_own_content` VALUES ('0', '39');
INSERT INTO `feed_own_content` VALUES ('0', '40');
INSERT INTO `feed_own_content` VALUES ('0', '41');
INSERT INTO `feed_own_content` VALUES ('0', '42');
INSERT INTO `feed_own_content` VALUES ('0', '43');
INSERT INTO `feed_own_content` VALUES ('0', '44');
INSERT INTO `feed_own_content` VALUES ('0', '45');
INSERT INTO `feed_own_content` VALUES ('0', '46');
INSERT INTO `feed_own_content` VALUES ('0', '47');
INSERT INTO `feed_own_content` VALUES ('0', '48');
INSERT INTO `feed_own_content` VALUES ('0', '49');
INSERT INTO `feed_own_content` VALUES ('0', '50');
INSERT INTO `feed_own_content` VALUES ('0', '51');
INSERT INTO `feed_own_content` VALUES ('0', '52');
INSERT INTO `feed_own_content` VALUES ('0', '53');
INSERT INTO `feed_own_content` VALUES ('0', '54');

-- ----------------------------
-- Table structure for site
-- ----------------------------
DROP TABLE IF EXISTS `site`;
CREATE TABLE `site` (
  `id` int(10) unsigned NOT NULL,
  `url` varchar(512) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of site
-- ----------------------------
INSERT INTO `site` VALUES ('0', 'http://blog.zhaojie.me/rss');
INSERT INTO `site` VALUES ('1', 'http://coolshell.cn/feed');

-- ----------------------------
-- Table structure for site_donate_feed
-- ----------------------------
DROP TABLE IF EXISTS `site_donate_feed`;
CREATE TABLE `site_donate_feed` (
  `site_id` int(10) unsigned NOT NULL,
  `feed_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`site_id`,`feed_id`),
  KEY `site_donate_feed_ibfk_1` (`feed_id`),
  CONSTRAINT `site_donate_feed_ibfk_1` FOREIGN KEY (`feed_id`) REFERENCES `feed` (`feed_id`),
  CONSTRAINT `site_donate_feed_ibfk_2` FOREIGN KEY (`site_id`) REFERENCES `site` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of site_donate_feed
-- ----------------------------
INSERT INTO `site_donate_feed` VALUES ('0', '0');
INSERT INTO `site_donate_feed` VALUES ('1', '1');

-- ----------------------------
-- Table structure for storage
-- ----------------------------
DROP TABLE IF EXISTS `storage`;
CREATE TABLE `storage` (
  `id` int(10) unsigned NOT NULL,
  `feed_id` int(10) unsigned NOT NULL,
  `path` varchar(512) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `feed_id` (`feed_id`),
  CONSTRAINT `storage_ibfk_1` FOREIGN KEY (`feed_id`) REFERENCES `feed` (`feed_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of storage
-- ----------------------------
INSERT INTO `storage` VALUES ('0', '0', 'F:/Qt_workplace/RSStalk/RSStalk/build-RSStalk-Desktop_Qt_5_7_0_MSVC2015_64bit-Debug/XML/老赵点滴 - 追求编程之美.xml');
INSERT INTO `storage` VALUES ('1', '1', 'F:/Qt_workplace/RSStalk/RSStalk/build-RSStalk-Desktop_Qt_5_7_0_MSVC2015_64bit-Debug/XML/酷 壳 – CoolShell.cn.xml');

-- ----------------------------
-- Table structure for storage_store_feed
-- ----------------------------
DROP TABLE IF EXISTS `storage_store_feed`;
CREATE TABLE `storage_store_feed` (
  `storage_id` int(10) unsigned NOT NULL,
  `feed_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`storage_id`,`feed_id`),
  KEY `storage_store_feed_ibfk_1` (`feed_id`),
  CONSTRAINT `storage_store_feed_ibfk_1` FOREIGN KEY (`feed_id`) REFERENCES `feed` (`feed_id`),
  CONSTRAINT `storage_store_feed_ibfk_2` FOREIGN KEY (`storage_id`) REFERENCES `storage` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of storage_store_feed
-- ----------------------------
INSERT INTO `storage_store_feed` VALUES ('0', '0');
INSERT INTO `storage_store_feed` VALUES ('1', '1');

-- ----------------------------
-- View structure for show_favorite_content
-- ----------------------------
DROP VIEW IF EXISTS `show_favorite_content`;
CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `show_favorite_content` AS select `contents`.`title` AS `title` from `contents` where (`contents`.`favorite` = TRUE) ;

-- ----------------------------
-- View structure for show_feed
-- ----------------------------
DROP VIEW IF EXISTS `show_feed`;
CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `show_feed` AS select `class`.`name` AS `class`,`feed`.`title` AS `feed` from (`feed` join `class` on((`feed`.`class_id` = `class`.`id`))) ;

-- ----------------------------
-- View structure for show_feed_store_path
-- ----------------------------
DROP VIEW IF EXISTS `show_feed_store_path`;
CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `show_feed_store_path` AS select `feed`.`title` AS `title`,`storage`.`path` AS `path` from (`feed` join `storage` on((`feed`.`feed_id` = `storage`.`feed_id`))) ;

-- ----------------------------
-- View structure for show_site
-- ----------------------------
DROP VIEW IF EXISTS `show_site`;
CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `show_site` AS select `site`.`url` AS `url` from `site` ;
