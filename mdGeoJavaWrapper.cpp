#include <jni.h>

#include "mdGeo.h"

class Utf8String {
	private:
		JNIEnv* env;
		const char* utf8Ptr;
		jstring jString;
	public:
		Utf8String(JNIEnv* jEnv,jstring str);
		~Utf8String();
		const char* GetUtf8Ptr();
};

Utf8String::Utf8String(JNIEnv* jEnv,jstring str) {
	env=jEnv;
	jString=str;
	if (jString!=0)
		utf8Ptr=env->GetStringUTFChars(jString,0);
	else
		utf8Ptr=0;
}

Utf8String::~Utf8String() {
	if (utf8Ptr!=0)
		env->ReleaseStringUTFChars(jString,utf8Ptr);
}

const char* Utf8String::GetUtf8Ptr() {
	if (utf8Ptr!=0)
		return utf8Ptr;
	return "";
}

jstring UnicodeString(JNIEnv* jEnv,const char* str) {
	if (str!=0)
		return jEnv->NewStringUTF(str);
	return jEnv->NewStringUTF("");
}

extern "C" JNIEXPORT jlong JNICALL Java_com_melissadata_mdGeoJNI_mdGeoCreate(JNIEnv* /*jEnv*/,jclass /*jCls*/) {
	return (jlong) new mdGeo();
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdGeoJNI_mdGeoDestroy(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I) {
	delete (mdGeo*) I;
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdGeoJNI_SetPathToGeoCodeDataFiles(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring p1) {
	Utf8String _p1(jEnv,p1);
	((mdGeo*) I)->SetPathToGeoCodeDataFiles(_p1.GetUtf8Ptr());
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdGeoJNI_SetPathToGeoPointDataFiles(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring p1) {
	Utf8String _p1(jEnv,p1);
	((mdGeo*) I)->SetPathToGeoPointDataFiles(_p1.GetUtf8Ptr());
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdGeoJNI_SetPathToGeoCanadaDataFiles(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring p1) {
	Utf8String _p1(jEnv,p1);
	((mdGeo*) I)->SetPathToGeoCanadaDataFiles(_p1.GetUtf8Ptr());
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_melissadata_mdGeoJNI_SetLicenseString(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring License) {
	Utf8String _License(jEnv,License);
	return (jboolean) ((mdGeo*) I)->SetLicenseString(_License.GetUtf8Ptr());
}

extern "C" JNIEXPORT jint JNICALL Java_com_melissadata_mdGeoJNI_Initialize(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring DataPath,jstring IndexPath) {
	Utf8String _DataPath(jEnv,DataPath);
	Utf8String _IndexPath(jEnv,IndexPath);
	return (jint) ((mdGeo*) I)->Initialize(_DataPath.GetUtf8Ptr(),_IndexPath.GetUtf8Ptr());
}

extern "C" JNIEXPORT jint JNICALL Java_com_melissadata_mdGeoJNI_InitializeDataFiles(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I) {
	return (jint) ((mdGeo*) I)->InitializeDataFiles();
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetInitializeErrorString(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetInitializeErrorString());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetBuildNumber(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetBuildNumber());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetDatabaseDate(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetDatabaseDate());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetExpirationDate(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetExpirationDate());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetLicenseExpirationDate(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetLicenseExpirationDate());
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdGeoJNI_SetLatitude(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring latitude) {
	Utf8String _latitude(jEnv,latitude);
	((mdGeo*) I)->SetLatitude(_latitude.GetUtf8Ptr());
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdGeoJNI_SetLongitude(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring longitude) {
	Utf8String _longitude(jEnv,longitude);
	((mdGeo*) I)->SetLongitude(_longitude.GetUtf8Ptr());
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_melissadata_mdGeoJNI_WriteToLogFile(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring logFile) {
	Utf8String _logFile(jEnv,logFile);
	return (jboolean) ((mdGeo*) I)->WriteToLogFile(_logFile.GetUtf8Ptr());
}

extern "C" JNIEXPORT jint JNICALL Java_com_melissadata_mdGeoJNI_GeoCode(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring Zip,jstring Plus4) {
	Utf8String _Zip(jEnv,Zip);
	Utf8String _Plus4(jEnv,Plus4);
	return (jint) ((mdGeo*) I)->GeoCode(_Zip.GetUtf8Ptr(),_Plus4.GetUtf8Ptr());
}

extern "C" JNIEXPORT jint JNICALL Java_com_melissadata_mdGeoJNI_GeoPoint(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring Zip,jstring Plus4,jstring DeliveryPointCode) {
	Utf8String _Zip(jEnv,Zip);
	Utf8String _Plus4(jEnv,Plus4);
	Utf8String _DeliveryPointCode(jEnv,DeliveryPointCode);
	return (jint) ((mdGeo*) I)->GeoPoint(_Zip.GetUtf8Ptr(),_Plus4.GetUtf8Ptr(),_DeliveryPointCode.GetUtf8Ptr());
}

extern "C" JNIEXPORT jdouble JNICALL Java_com_melissadata_mdGeoJNI_ComputeDistance(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I,jdouble Latitude1,jdouble Longitude1,jdouble Latitude2,jdouble Longitude2) {
	return (jdouble) ((mdGeo*) I)->ComputeDistance((double) Latitude1,(double) Longitude1,(double) Latitude2,(double) Longitude2);
}

extern "C" JNIEXPORT jdouble JNICALL Java_com_melissadata_mdGeoJNI_ComputeBearing(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I,jdouble Latitude1,jdouble Longitude1,jdouble Latitude2,jdouble Longitude2) {
	return (jdouble) ((mdGeo*) I)->ComputeBearing((double) Latitude1,(double) Longitude1,(double) Latitude2,(double) Longitude2);
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetErrorCode(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetErrorCode());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetStatusCode(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetStatusCode());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetResults(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetResults());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetResultCodeDescription(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring resultCode,jint opt) {
	Utf8String _resultCode(jEnv,resultCode);
	return UnicodeString(jEnv,((mdGeo*) I)->GetResultCodeDescription(_resultCode.GetUtf8Ptr(),(mdGeo::ResultCdDescOpt) opt));
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetLatitude(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetLatitude());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetLongitude(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetLongitude());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetCensusTract(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetCensusTract());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetCensusBlock(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetCensusBlock());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetCountyFips(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetCountyFips());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetCountyName(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetCountyName());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetPlaceCode(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetPlaceCode());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetPlaceName(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetPlaceName());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetTimeZoneCode(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetTimeZoneCode());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetTimeZone(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetTimeZone());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetCBSACode(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetCBSACode());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetCBSATitle(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetCBSATitle());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetCBSALevel(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetCBSALevel());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetCBSADivisionCode(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetCBSADivisionCode());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetCBSADivisionTitle(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetCBSADivisionTitle());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetCBSADivisionLevel(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetCBSADivisionLevel());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetLastUsageLogMessage(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetLastUsageLogMessage());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetCensusKey(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetCensusKey());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetCountySubdivisionCode(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetCountySubdivisionCode());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetCountySubdivisionName(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetCountySubdivisionName());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetElementarySchoolDistrictCode(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetElementarySchoolDistrictCode());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetElementarySchoolDistrictName(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetElementarySchoolDistrictName());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetSecondarySchoolDistrictCode(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetSecondarySchoolDistrictCode());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetSecondarySchoolDistrictName(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetSecondarySchoolDistrictName());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetStateDistrictLower(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetStateDistrictLower());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetStateDistrictUpper(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetStateDistrictUpper());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetUnifiedSchoolDistrictCode(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetUnifiedSchoolDistrictCode());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetUnifiedSchoolDistrictName(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetUnifiedSchoolDistrictName());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetBlockSuffix(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGeo*) I)->GetBlockSuffix());
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_melissadata_mdGeoJNI_SetInputParameter(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring key,jstring val) {
	Utf8String _key(jEnv,key);
	Utf8String _val(jEnv,val);
	return (jboolean) ((mdGeo*) I)->SetInputParameter(_key.GetUtf8Ptr(),_val.GetUtf8Ptr());
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdGeoJNI_FindGeo(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I) {
	((mdGeo*) I)->FindGeo();
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGeoJNI_GetOutputParameter(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring key) {
	Utf8String _key(jEnv,key);
	return UnicodeString(jEnv,((mdGeo*) I)->GetOutputParameter(_key.GetUtf8Ptr()));
}

