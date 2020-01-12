#include "timestamp.h"
using namespace std;

int main(int argc, char** argv) {
  QString str = argv[1];
  QDir dir;
  //  cout << endl << argv[0] << endl;
  dir.setPath(str);
  start(dir, str);
  cout << "Parsing " << number << " ini files. " << endl
       << "Creatimg file: parsing_ini_files.txt" << endl;
  return 0;
}

//Регулярные выражения
/* Проверка ГРЗ - ^ начало \d - цифровой символ далее русский алфавит один
 * или более раз и $ конец 2 или 3 буквы   */
// const QString kRegularRegistrationNumber = R"(^([\dа-яА-Я]+)(\w{2,3})$)";
// Проверка имени фала
// const QString kRegularFilesFormatValid = R"((\d+)\.*(\w+)\.*(\w*)\.+(\w+)$)";

void start(const QDir& dir, const QString patch) {
  data_to_write.clear();
  QApplication::processEvents();

  QStringList listFiles = dir.entryList(QDir::Files);
  number = listFiles.size();
  for (auto& file : listFiles) {
    QString name;
    name = patch + file;
    QSettings settings(name, QSettings::IniFormat);
    settings.beginGroup("Snapshot");
    QString complex_name = settings.value("complex_name").toString();
    QString delta = settings.value("delta").toString();
    QString factor = settings.value("factor").toString();
    QStringList images = settings.value("images").toStringList();
    QString path_to_images = settings.value("path_to_images").toString();
    QString traffic_light_time =
        settings.value("traffic_light_time").toString();
    QString video_after = settings.value("video_after").toString();
    QString video_before = settings.value("video_before").toString();

    data_to_write.append("complex_name - ");
    data_to_write.append(complex_name);
    data_to_write.append(", delta-");
    data_to_write.append(delta);
    data_to_write.append(", factor-");
    data_to_write.append(factor);
    data_to_write.append(", patch - ");
    data_to_write.append(path_to_images);
    data_to_write.append(", traffic_light_time-");
    data_to_write.append(traffic_light_time);
    data_to_write.append(", video_after-");
    data_to_write.append(video_after);
    data_to_write.append(", video_before-");
    data_to_write.append(video_before);
    data_to_write.append("\n");
    data_to_write.append("images1-");
    data_to_write.append(images[0]);
    data_to_write.append(", time - ");
    data_to_write.append(Get_time(images[0]));
    data_to_write.append("\n");
    data_to_write.append("images2-");
    data_to_write.append(images[1]);
    data_to_write.append(", time - ");
    data_to_write.append(Get_time(images[1]));
    data_to_write.append("\n");
    data_to_write.append("images3-");
    data_to_write.append(images[2]);
    data_to_write.append(", time - ");
    data_to_write.append(Get_time(images[2]));
    data_to_write.append("\n");
    data_to_write.append("images4-");
    data_to_write.append(images[3]);
    data_to_write.append(", time - ");
    data_to_write.append(Get_time(images[3]));
    data_to_write.append("\n");
    data_to_write.append("images5-");
    data_to_write.append(images[4]);
    data_to_write.append(", time - ");
    data_to_write.append(Get_time(images[4]));
    data_to_write.append("\n");
    data_to_write.append("images6-");
    data_to_write.append(images[5]);
    data_to_write.append(", time - ");
    data_to_write.append(Get_time(images[5]));
    data_to_write.append("\n");
    data_to_write.append("images7-");
    data_to_write.append(images[6]);
    data_to_write.append(", time - ");
    data_to_write.append(Get_time(images[6]));
    data_to_write.append("\n");
    data_to_write.append("\n");
    settings.endGroup();
  }
  QFile out_data;
  out_data.setFileName("parsing_ini_files.txt");
  out_data.open(QIODevice::WriteOnly);
  out_data.write(data_to_write);
  out_data.close();
}

QString Get_time(QString images) {
  QString time_images;
  for (int i = 0; i < 13; ++i) {
    time_images[i] = images[i];
  }
  qint64 time_64 = static_cast<qint64>(time_images.toLongLong());
  QDateTime date;
  //    date = QDateTime::currentDateTime();
  //    cout << date.toMSecsSinceEpoch() << endl;
  date = QDateTime::fromMSecsSinceEpoch(time_64);
  //        cout << date.toString(DateTimeFormat).toStdString() << endl;
  return date.toString(DateTimeFormat);
}
