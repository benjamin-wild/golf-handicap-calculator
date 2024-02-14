PRAGMA foreign_keys = ON;

INSERT INTO users(username, fullname, password, handicap_index)
VALUES ('benwild', 'Benjamin Wild', 'test-password', '2.6');

INSERT INTO scores(owner, score_id, course, score, slope_rating, course_rating, user_review)
VALUES ('benwild', '1', 'UMGC', '78', '134', '72.8', 'N/A'); 